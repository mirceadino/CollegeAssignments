#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char* argv[])
{
  int client_sock;
  SockAddrIn server;
  char* ip = argv[1];
  int port = atoi(argv[2]);

  client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (client_sock < 0)
  {
    ERROR("error: can't establish socket.");
    return -1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(port);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ip);

  if (connect(client_sock, (SockAddr*)&server,  sizeof(server)) < 0)
  {
    ERROR("error: could not connect to server.");
    return -2;
  }

  int n, a, sum;
  printf("n = ");
  scanf("%d", &n);
  n = ntohs(n);
  send(client_sock, &n, sizeof(n), 0);
  n = htons(n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a);
    a = htons(a);
    send(client_sock, &a, sizeof(a), 0);
  }

  recv(client_sock, &sum, sizeof(sum), MSG_WAITALL);
  sum = ntohs(sum);

  printf("Sum is %d\n", sum);

  close(client_sock);

  return 0;
}
