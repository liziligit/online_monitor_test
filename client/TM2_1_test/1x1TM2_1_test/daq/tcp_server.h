#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
  
  

#define BACKLOG 1
#define MAXRECVLEN 1024
  
class tcp_server  
{  
private:  
    char buf[MAXRECVLEN];
    int listenfd, connectfd;  /* socket descriptors */
    struct sockaddr_in server; /* server's address information */
    struct sockaddr_in client; /* client's address information */
    socklen_t addrlen;

    /* set socket option */
    int opt;
  
public:  
        tcp_server(int listen_port);  
        int recv_msg();  
};  
