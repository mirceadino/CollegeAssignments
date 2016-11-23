typedef struct sockaddr_in SockAddrIn;
typedef struct sockaddr SockAddr;

#define ERROR(s) \
  fprintf(stderr, s); \
  fprintf(stderr, "\n")
