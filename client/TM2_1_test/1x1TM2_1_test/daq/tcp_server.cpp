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
        //printf("You got a connection from client's ip %s, port %d at time %ld.%ld\n",inet_ntoa(client.sin_addr),htons(client.sin_port), tv.tv_sec,tv.tv_usec);
        
        int iret=-1;
        while(1)
        {
            iret = recv(connectfd, buf, MAXRECVLEN, 0);
            if(iret>0)
            {
                printf("%s\n", buf);
            }else
            {
                close(connectfd);
                break;
            }
            /* print client's ip and port */
            //send(connectfd, buf, iret, 0); /* send to the client welcome message */
	    if(strcmp(buf,"ini")==0){
		system("./runTm2-.sh");
	    }
	    if(strcmp(buf,"start")==0){
                system("./mytcp -c realTime.c");
	    }	
	    if(strcmp(buf,"take")==0){
                system("./realTime.ce -fileEnd 5");
	    }
	    if(strcmp(buf,"save")==0){
               system("./realTime.ce -displayMode 2");
	    }	
            memset(buf,0,sizeof(buf));		
        }
    }
    close(listenfd); /* close listenfd */
        return 0;  
}  
