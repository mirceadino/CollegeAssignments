#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define warning(...) fprintf(stderr, "warning: "),\
                     fprintf(stderr, __VA_ARGS__),\
                     fprintf(stderr, "\n");
#define error(...) fprintf(stderr, "error: "),\
                   fprintf(stderr, __VA_ARGS__),\
                   fprintf(stderr, "\n"),\
                   exit(1);

typedef struct sockaddr SockAddr;
typedef struct sockaddr_in SockAddrIn;
typedef struct hostent HostEnt;

#define BUFFLEN 1024

int main(int argc, char* argv[])
{
  int sock, port, num_recv_bytes, num_sent_bytes;
  socklen_t fromlen;
  SockAddrIn server, from;
  HostEnt* hp;
  char buffer[BUFFLEN + 1];

  if (argc < 3)
  {
    error("not enough parameters\nusage: %s <server> <port>", argv[0]);
  }

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0)
  {
    error("can't open socket");
  }

  hp = gethostbyname(argv[1]);
  if (hp == NULL)
  {
    error("unknown host");
  }
  port = atoi(argv[2]);

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);

  fromlen = sizeof(from);

  printf("Please enter the message: ");
  scanf("%s", buffer);

  double begin_time = clock();

  num_sent_bytes = sendto(sock, buffer, strlen(buffer), 0, (SockAddr*)&server,
                          fromlen);
  if (num_sent_bytes < 0)
  {
    error("can't send");
  }

  num_recv_bytes = recvfrom(sock, buffer, BUFFLEN, 0, (SockAddr*)&from, &fromlen);
  if (num_recv_bytes < 0)
  {
    error("can't receive");
  }

  double end_time = clock();

  printf("Received a message: %s\n", buffer);
  printf("Time: %fs\n", (end_time - begin_time) / CLOCKS_PER_SEC);

  return 0;
}
