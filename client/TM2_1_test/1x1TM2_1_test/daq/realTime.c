// bind process to cpu
cpu_set_t process_mask;
CPU_ZERO(&process_mask);
CPU_SET(0,&process_mask);
if(sched_setaffinity(0, sizeof(process_mask),&process_mask)<0){
	perror("sched_setaffinity");
}


//bind pthread to cpu
cpu_set_t pthread_mask; // transfer cpu_set to pthread by processPara
CPU_ZERO(&pthread_mask);
CPU_SET(1,&pthread_mask);
CPU_SET(2,&pthread_mask);
CPU_SET(3,&pthread_mask);


////////////////////////////////////////////////////////// parameter
int sampleBytes=1024*1024*480;

char fn[200]="../data/out";
char mode[200]="wb";                                                                
int fileStart = 0;
int fileEnd = 1;  
int displayMode=2; // 0: pd3 display; 1: pd1 display; 2: no display,save pd1 file
int ip=1;
char *tmpBuf = new char[5184*3*4+4];   //  用来保留上一次采样剩下的不完整的一帧数据，
char *tmpBufOrder = new char[int(sampleBytes*1.5)];   //  用来保留上转化成ADC值之后的数据，
int tmpSize;  // 不完整数据的大小 （byte为单位）


pid=para((char*)"-sampleBytes");  
if(pid>0){
	sampleBytes=atoi(argv[pid+1]);
}

pid=para((char*)"-fn");  
if(pid>0){
	sprintf(fn,"%s",argv[pid+1]);
}



pid=para((char*)"-fileStart");  
if(pid>0){
	fileStart=atoi(argv[pid+1]);
}

pid=para((char*)"-fileEnd");  
if(pid>0){
	fileEnd=atoi(argv[pid+1]);
}

pid=para((char*)"-displayMode");
if(pid>0){
	displayMode=atoi(argv[pid+1]);
}

pid=para((char*)"-IP");
if(pid>0){
	ip=atoi(argv[pid+1]);
}


int pedeId, polNId;
pedeId=0;
polNId=78;

pid=para((char*)"-pedeId");  
if(pid>0){
	pedeId=atoi(argv[pid+1]);
}
pid=para((char*)"-polNId");  
if(pid>0){
	polNId=atoi(argv[pid+1]);
}

char pedeName[200];
char polName[200];
char polRevName[200];
sprintf(pedeName,"../data/pedeData/xpede_%d",pedeId);
sprintf(polName,"../data/tauData/polNPar_%d.txt",polNId);
sprintf(polRevName,"../data/tauData/polNParRev_%d.txt",polNId);

pd1Pede pede;
pede.setup(pedeName);

polNLoad polPar;
polPar.loadPar(polName);
polPar.loadParRev(polRevName);

/******** send data to main control ******************/
//tcp_client ts;
//ts.setup((char*)"192.168.3.1",1234);


char *buf=new char[sampleBytes];
char *bufN=new char[sampleBytes];

pthread_t pt;
pthread_t ptN;
int ptFlag = 0;
int ptNFlag = 0; 
int err;

processPara pp;
processPara ppN;
pp.p=buf;
pp.sampleBytes=sampleBytes;
pp.fn=fn;
pp.tmpBuf=tmpBuf;
pp.tmpBufOrder=tmpBufOrder;
pp.tmpSize=0;
pp.fileStart=fileStart;
pp.displayMode = displayMode;
pp.cpuSet = pthread_mask;
pp.tcp_send = ts;
pp.meanPed = pede.meanPed;
pp.rmsPed = pede.rmsPed;
pp.polNPar = polPar.polNPar;
pp.polNParRev = polPar.polNParRev;
pp.IP=ip;

ppN.p=bufN;
ppN.sampleBytes=sampleBytes;
ppN.fn=fn;
ppN.tmpBuf=tmpBuf;
ppN.tmpBufOrder=tmpBufOrder;
ppN.tmpSize=0;
ppN.fileStart=fileStart;
ppN.displayMode = displayMode;
ppN.cpuSet = pthread_mask;
ppN.tcp_send = ts;
ppN.meanPed = pede.meanPed;
ppN.rmsPed = pede.rmsPed;
ppN.polNPar = polPar.polNPar;
ppN.polNParRev = polPar.polNParRev;
ppN.IP=ip;


for(int i=fileStart;i<fileEnd;i++){

	cout<<fileEnd<<"----------------"<<i<<endl;
	askTcpData(sampleBytes);//set ethernet transmission data size in byte

	int n=0;
	if(i%2==0){
    	n=read_mem_ns(buf,sampleBytes);// get data from FPGA	
	pp.fileNum = i;
        pp.tmpSize=ppN.tmpSize;
	ptFlag=1;	
	err=pthread_create(&pt,NULL, rtprocess,(void*)(&pp));// using thread to analysis data
        //rtprocess((void*)(&pp));
	}
    else{
		
    	n=read_mem_ns(bufN,sampleBytes);	
	ppN.fileNum = i;
	ppN.tmpSize=pp.tmpSize;
	ptNFlag = 1;
	err=pthread_create(&ptN,NULL, rtprocess,(void*)(&ppN));
        //rtprocess((void*)(&ppN));

	}
	cout<<n<<" bytes is read"<<endl;

//if(err!=0){
//	cout<<"thread error"<<endl;	
//}	


}

if(ptFlag==1) 
pthread_join(pt, NULL);
if(ptNFlag == 1)
pthread_join(ptN, NULL); 	  
	delete [] buf;  
	delete [] bufN;  
	delete [] tmpBuf;
	delete [] tmpBufOrder;  

