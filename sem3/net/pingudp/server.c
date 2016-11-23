#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define warning(...) fprintf(stderr, "warning: "),\
                     fprintf(stderr, __VA_ARGS__),\
                     fprintf(stderr, "\n");
#define error(...) fprintf(stderr, "error: "),\
                   fprintf(stderr, __VA_ARGS__),\
                   fprintf(stderr, "\n"),\
                   exit(1);

typedef struct sockaddr SockAddr;
typedef struct sockaddr_in SockAddrIn;

#define BUFFLEN 1024

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    error("not enough parameters\nusage: %s <port>", argv[0]);
  }

  int sock, port, num_recv_bytes, num_sent_bytes;
  socklen_t fromlen;
  SockAddrIn server, from;
  char buffer[BUFFLEN + 1];

  port = atoi(argv[1]);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0)
  {
    error("can't open socket");
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  if (bind(sock, (SockAddr*)&server, sizeof(server)) < 0)
  {
    error("can't bind");
  }

  fromlen = sizeof(from);

  for (;;)
  {
    num_recv_bytes = recvfrom(sock, buffer, BUFFLEN, 0, (SockAddr*)&from, &fromlen);
    if (num_recv_bytes < 0)
    {
      error("can't receive");
    }

    buffer[num_recv_bytes] = 0;
    printf("Received a datagram: \n");
    printf("%s\n", buffer);


    num_sent_bytes = sendto(sock, buffer, BUFFLEN, 0, (SockAddr*)&from, fromlen);
    if (num_sent_bytes < 0)
    {
      error("can't send");
    }
  }

  return 0;
}
