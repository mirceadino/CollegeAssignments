#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "utils.h"

int main(int argc, char* argv[])
{
  int sock;
  struct sockaddr_in server;
  int port;
  char* filename;

  if (argc < 3)
  {
    fprintf(stderr, "usage: %s <port> <filename>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[1]);
  filename = argv[2];

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
    fprintf(stderr, "error: can't establish socket.\n");
    exit(1);
  }

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(port);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sock, (struct sockaddr*)&server,  sizeof(server)) < 0)
  {
    fprintf(stderr, "error: could not connect to server.\n");
    exit(1);
  }

  int type = SPECIAL;
  type = htons(type);
  send(sock, &type, sizeof(type), 0);

  int file = open(filename, O_RDONLY);
  char buffer[OMAX + 1];

  while (1)
  {
    int num = read(file, buffer, OMAX);
    send(sock, buffer, num * sizeof(char), 0);
    if (num < OMAX)
    {
      break;
    }
    sleep(1);
  }

  close(file);
  close(sock);

  return 0;
}
