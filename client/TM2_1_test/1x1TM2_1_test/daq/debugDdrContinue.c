////////////////////////////////////////////////////////// parameter

int sampleBytes=1024*1024*1;
char *buf=new char[sampleBytes];
Sleep(1000);

int n = 0;
askTcpData(sampleBytes);

n=read_mem_ns(buf,sampleBytes);	

cout<<n<<" bytes is read"<<endl;	


unsigned int *pi=(unsigned int *)buf;

ddrDataContinueMode da;
// data continuity  

int error = 0;
int pp=0;
int nFrame=0;
int flag=0;
   for(int j=0; j<(sampleBytes)/4; j++) {
	 if((pi[j]& 0x00ffffff)==0x55aaaa){
			 if(flag ==0){
				flag =1;
				continue;				
				}
			if(flag ==1){
			 if(pp == 0){
				pp = j;
				cout<<"secondFramePosition = "<<j<<endl;
				continue;
			 }
			 else{
				
				if((j-pp)!=15553){
					printf("j = %d     di = %d\n", j,j-pp);
					cout<<"Discontinuous Data at nFrame = "<<nFrame<<endl;
					return 0;
					 }
				else{
					
					nFrame++;
				}			 
		


			    	pp=j;
			  }
			}


	 }
	}
		
 cout<<"nFrame = "<<nFrame<<endl; 
	if(nFrame==0){
		cout<<"Wrong Data!\n";
		return 0;
	}

// data correction

int start=0;
int b=0;
flag=0;

    for(int i=0; i<(sampleBytes)/4; i++) {
        // cout << "i = " << i <<endl;

	 if((pi[i]& 0x00ffffff)==0x55aaaa){
		if(flag==0){
		flag=1;
		continue;		
		}
		 start=1;
		 b=0;
                 printf(" %x\n ", pi[i]);
		 continue;
		 
	 }

	 
	 if(start==1){
		 da.ip=(char*)(pi+i);
        int ret=da.fill();
		 if(b<8){
        da.print();}
             else{break;}
			
        i=i+2;		
	 }
	 
	 
		b++;
		
    }
/*
////////////////////////////////////////////////////
flag=0;
unsigned int secondFrameFlag;

    for(int i=0; i<(sampleBytes)/4; i++) {
	 if((pi[i]& 0x00ffffff)==0x55aaaa){
		if(flag==0){
		flag=1;
		continue;		
		}
		secondFrameFlag = pi[i];
                 printf(" %x\n ", secondFrameFlag);
		break;
		 
	 }
	
    }

flag=0;
unsigned int lastSecondFrameFlag;
    for(int i=0; i<(sampleBytes)/4; i++) {
	 if((pi[sampleBytes/4-(i+1)]& 0x00ffffff)==0x55aaaa){
		if(flag==0){
		flag=1;
		continue;		
		}
		lastSecondFrameFlag = pi[sampleBytes/4-(i+1)];
                 printf(" %x\n ", lastSecondFrameFlag);
		 break;
	 }

	 
	
    }*/
	  
	delete [] buf;  

