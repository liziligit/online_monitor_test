#include "tcp_client.h"
#include <iostream>
#include <fstream>
using namespace std;

int help=0;
int pid;
int gargc;
char** gargv;
int para(char *a){
	if(help==1)
		cout<<a<<" ";
	int i;
	for(i=0;i<gargc;i++){
		if(strcmp(a,gargv[i])==0) 
			return i;
		}
	return -1;
}


int main(int argc, char *argv[])
{
	gargc=argc;
	gargv=argv;
	char p[200]="./initiTm2-.sh 78";
	pid=para((char*)"-cmd"); 
	/*if(pid>0){
		strcpy(p,"");
		for(int i=pid+1; i<gargc; i++){
			strcat(p,gargv[i]);
			strcat(p," ");
		}
	}*/
	if(pid>0){
	       
		sprintf(p, "%s", argv[pid+1]);
	}        
	printf("%s\n",p);	
	int ip=1;
	pid=para((char*)"-IP");
	if(pid>0){
	       
		ip=atoi(argv[pid+1]);
	}	
	if(ip==1){
		tcp_client ts((char*)"192.168.3.201",4321);
		ts.sendBuf(p, strlen(p));
        }
	if(ip==2){
		tcp_client ts((char*)"192.168.3.202",4321);
		ts.sendBuf(p, strlen(p));
	}
	// if(ip==3){
	// 	tcp_client ts((char*)"192.168.3.203",4321);
	// 	ts.sendBuf(p, strlen(p));
	// }
	// if(ip==4){
	// 	tcp_client ts((char*)"192.168.3.204",4321);
	// 	ts.sendBuf(p, strlen(p));
	// }

	return 0;
}
