#include "tcp_client.h"  
  
tcp_client::tcp_client(char* serverIP, int connectPort) {  
    
    if((he=gethostbyname(serverIP))==NULL)
    {
        printf("gethostbyname() error\n");
        exit(1);
    }
    
    if((sockfd=socket(AF_INET,SOCK_STREAM, 0))==-1)
    {
        printf("socket() error\n");
        exit(1);
    }
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(connectPort);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server))==-1)
    {
        printf("connect() error\n");
        exit(1);
    }


}  
  
int tcp_client::sendBuf(char *buf,int length) {  
  
return send(sockfd,buf,length,0);
          
}  


int tcp_client::readBuf(char *buf,int length) {  
  
return recv(sockfd,buf,length,0);
          
}  
