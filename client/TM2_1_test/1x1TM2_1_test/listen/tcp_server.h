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
#define MAXRECVLEN 11522
#define Sleep(x) (usleep((x)*1000))  

#include "rootlib.h"
class tcp_server  
{  
public:  
    char buf[MAXRECVLEN];
    int listenfd, connectfd;  /* socket descriptors */
    struct sockaddr_in server; /* server's address information */
    struct sockaddr_in client; /* client's address information */
    socklen_t addrlen;
    /* set socket option */
    int opt;
  
  

	void setup(int listen_port){  
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
          
};  

void* recv_msg(void *arg) {
	processPara *proPar=(processPara*)arg;  

        int nChip,nRow,nTimes;
	nChip=proPar->nChip;
	nRow=proPar->nRow;
	nTimes=proPar->nTimes;


	plot pt;
	pt=proPar->pt;


    	char *buf;
    	int listenfd, connectfd;  /* socket descriptors */
    	struct sockaddr_in server; /* server's address information */
    	struct sockaddr_in client; /* client's address information */
    	socklen_t addrlen;
	buf=proPar->buf;
	listenfd=proPar->listenfd;
	connectfd=proPar->connectfd;
	server=proPar->server;
	client=proPar->client;
	addrlen=proPar->addrlen;


	
	int charofFloat;
	charofFloat=10;
	float *averageData= new float[nChip*nRow*nTimes];
	int ip;

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
            iret = recv(connectfd, buf, MAXRECVLEN, MSG_WAITALL);

            if(iret>0)
            {  
		ip=atoi(buf);
		printf("\n%d\t%d",ip,iret);

		for(int i=0; i<nChip*nRow*nTimes;i++){
			averageData[i]=atof(buf+2+charofFloat*i);
		}
		
		for(int i=0; i<nTimes; i++){
		        pt.loadData2Hist1D(averageData, i, nChip, nRow);
		}
		pt.draw1D();
				
            }else
            {
                close(connectfd);
                break;
            }
            /* print client's ip and port */
            //send(connectfd, buf, iret, 0); /* send to the client welcome message */
	    //memset(buf,0,sizeof(buf));
        }

    }
    pt.delete1D();
    close(listenfd); /* close listenfd */
}  
