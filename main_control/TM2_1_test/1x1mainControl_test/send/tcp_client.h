#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  /* netdb is necessary for struct hostent */
#define PORT 4321  /* server port */

#define MAXDATASIZE 100

  
class tcp_client  
{  
private:  
    int sockfd, num;    /* files descriptors */
    char buf[MAXDATASIZE];    /* buf will store received text */
    struct hostent *he;    /* structure that will get information about remote host */
    struct sockaddr_in server;
  
public:  
        tcp_client(char *serverIP,int listen_port);  
 
		int sendBuf(char *buf,int length);
		int readBuf(char *buf,int length);
		
		
};  
