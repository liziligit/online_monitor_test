////////////////////////////////////////////////////////// parameter

int sampleBytes=1024*1024*45;   // large: 485M; small: 45M 
char fn[200]="../data/beam";
char mode[200]="wb";   
string dataType="pd1"; 
int fileId = 0;

pid=para((char*)"-sampleBytes");  
if(pid>0){
	sampleBytes=atoi(argv[pid+1]);
}

pid=para((char*)"-fn");  
if(pid>0){
	sprintf(fn,"%s",argv[pid+1]);
}

pid=para((char*)"-dataType");  
if(pid>0){
	dataType=argv[pid+1];
}

pid=para((char*)"-fileId");  
if(pid>0){
	fileId=atoi(argv[pid+1]);
}

char *buf=new char[sampleBytes];

int n = 0;
askTcpData(sampleBytes);
n=read_mem_ns(buf,sampleBytes);	
cout<<n<<" bytes is read"<<endl;	


unsigned int *pi=(unsigned int *)buf;



unsigned int secondFrameFlag;
unsigned int lastSecondFrameFlag;
unsigned int startFramePosition;
unsigned int endFramePosition;


int flag=0;
flag=0;
    for(int i=0; i<(sampleBytes)/4; i++) {
	 if((pi[i]& 0x00ffffff)==0x55aaaa){
		if(flag==0){
		flag=1;
		continue;		
		}
		secondFrameFlag= pi[i];
		startFramePosition=i;
		break;		 
	 }	
    }
flag=0;
    for(int i=0; i<(sampleBytes)/4; i++) {
	 if((pi[sampleBytes/4-(i+1)]& 0x00ffffff)==0x55aaaa){
		if(flag==0){
		flag=1;
		continue;		
		}
		lastSecondFrameFlag = pi[sampleBytes/4-(i+1)];
		endFramePosition=sampleBytes/4-(i+1);
		 break;
	 }	 
    }



placData_1 pd1;
pd1.createMem(1.5*(endFramePosition-startFramePosition)*4);
char fileName[500];
	if(dataType=="pd1"){
	pd1.debug=1;
	pd1.getDataHPdaq(buf,startFramePositionIP,endFramePositionIP);
	sprintf(fileName,"%s_%d.%s",fn,fileId,dataType.data());
	pd1.write(fileName);
  }  
delete [] buf; 


  
 

