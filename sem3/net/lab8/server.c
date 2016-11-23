#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include "utils.h"

#define DMAX 1500

pthread_mutex_t mtx;
char buffer[DMAX];
int buffer_len;
int continuing;

void* normal(void* args)
{
  int sock = *(int*)args;
  int bookmark = 0;

  printf("Normal client connected.\n");

  while (1)
  {
    pthread_mutex_lock(&mtx);
    if (bookmark < buffer_len)
    {
      int num = send(sock, buffer + bookmark, OMAX * sizeof(char), 0);
      if (num < 0)
      {
        fprintf(stderr, "error: can't send\n");
        exit(1);
      }
      bookmark += OMAX;
    }
    if (buffer_len == bookmark && continuing == 0)
    {
      int num = send(sock, buffer, 1, 0);
      pthread_mutex_unlock(&mtx);
      break;
    }
    pthread_mutex_unlock(&mtx);
  }

  return NULL;
}

void* special(void* args)
{
  int sock = *(int*)args;

  pthread_mutex_lock(&mtx);
  buffer_len = 0;
  pthread_mutex_unlock(&mtx);

  printf("Special client connected.\n");

  while (1)
  {
    pthread_mutex_lock(&mtx);

    int num = recv(sock, buffer + buffer_len, OMAX * sizeof(char), 0);
    if (num < 0)
    {
      fprintf(stderr, "error: can't receive\n");
      exit(1);
    }
    if (num == 0)
    {
      continuing = 0;
      pthread_mutex_unlock(&mtx);
      break;
    }
    buffer_len += OMAX;
    pthread_mutex_unlock(&mtx);
  }

  return NULL;
}

int main(int argc, char* argv[])
{
  int server_sock;
  struct sockaddr_in server, client;
  int port;

  if (argc < 2)
  {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[1]);

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0)
  {
    fprintf(stderr, "error: can't establish socket.\n");
    return -1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(port);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_sock, (struct sockaddr*)&server, sizeof(server)) < 0)
  {
    fprintf(stderr, "error: could not bind socket.\n");
    return -2;
  }

  listen(server_sock, 5);

  int client_sock;
  socklen_t len = sizeof(client);
  memset(&client, 0, sizeof(client));

  pthread_mutex_init(&mtx, 0);
  continuing = 1;

  while (1)
  {
    int type;
    pthread_t thread_id;
    client_sock = accept(server_sock, (struct sockaddr*)&client, &len);

    recv(client_sock, &type, sizeof(type), MSG_WAITALL);
    type = ntohs(type);

    if (type == SPECIAL)
    {
      pthread_create(&thread_id, 0, special, (void*)&client_sock);
    }
    else if (type == NORMAL)
    {
      pthread_create(&thread_id, 0, normal, (void*)&client_sock);
    }
  }

  return 0;
}
