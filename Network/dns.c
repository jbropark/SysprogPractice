#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "net.h"

int main(int argc, char *argv[])
{
  struct addrinfo *ai, *ai_it;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <domain name or dotted decial IP>\n", argv[0]); 
    exit(EXIT_FAILURE);
  }

  ai = getsocklist(argv[1], 0, AF_UNSPEC, SOCK_STREAM, 0, NULL);

  ai_it = ai;

  while (ai_it != NULL) {
    ai_it->ai_addr

    ai_it = ai_it->ai_next;
  }

  freeaddrinfo(ai);
}
