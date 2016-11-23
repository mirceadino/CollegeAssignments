#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char* argv[])
{
  int server_sock;
  SockAddrIn server, client;
  int port = atoi(argv[1]);

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0)
  {
    ERROR("error: can't establish socket.");
    return -1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(port);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_sock, (SockAddr*)&server, sizeof(server)) < 0)
  {
    ERROR("error: could not bind name to socket.");
    return -2;
  }

  listen(server_sock, 1);

  int client_sock;
  socklen_t len = sizeof(client);
  memset(&client, 0, sizeof(client));

  while (1)
  {
    int n, sum = 0;
    client_sock = accept(server_sock, (SockAddr*)&client, &len);
    printf("Client connected.\n");

    if (fork() == 0)
    {
      recv(client_sock, &n, sizeof(n), MSG_WAITALL);
      n = ntohs(n);

      for (int i = 0; i < n; ++i)
      {
        int a;
        recv(client_sock, &a, sizeof(a), MSG_WAITALL);
        a = ntohs(a);
        sum += a;
      }

      sum = htons(sum);
      send(client_sock, &sum, sizeof(sum), 0);

      close(client_sock);
      exit(0);
    }
    else
    {
      close(client_sock);
    }
  }

  return 0;
}
