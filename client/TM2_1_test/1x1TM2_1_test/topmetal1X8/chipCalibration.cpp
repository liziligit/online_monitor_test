#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TROOT.h>
#include <TMath.h>
#include <TParameter.h>
#include <TGraph.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <TSystem.h>
#include "rootlib.h"
#include "kbhit.h"


int main(int argc, char **argv){
char *infile;
infile = argv[1];
int fileId;
fileId = atol(argv[2]);
char *pedefile;
pedefile = argv[3];
int pedeId;
pedeId = atol(argv[4]);
int dimId;
dimId = atol(argv[5]);
int frame1Id;
frame1Id= atol(argv[6]);
int frame2Id;
frame2Id= atol(argv[7]);
double maxPixelSignal;
maxPixelSignal = atof(argv[8]);
double minPixelSignal;
minPixelSignal = atof(argv[9]);

char calibrationfn[100];
int nStrip=2;
pd1Pede pede[nStrip];
placData_1 pd1[nStrip];
char infn[100];
char pedefn[100];
int ip;
int frameId[nStrip];
frameId[0]=frame1Id;
frameId[1]=frame2Id;
int nPix, nCh;
nPix=72;
nCh=8;
wholeFrame wframe;
wframe.setuptmpHist2D(nCh,1,nPix,nPix,"hist2d");
double average[nStrip*nCh];
for(int i=0; i<nStrip; i++){
	if(dimId==1){
	ip=3+(dimId+i-1)*4;
	}
	if(dimId==2){
	ip=3+(dimId+i)*4;
	}
	sprintf(infn,"%sIP%d/beam_%d.pd1",infile, ip, fileId);
	sprintf(pedefn,"%sIP%d/pede_%d", pedefile, ip, pedeId);	
	sprintf(calibrationfn,"../data/tauData/chipCalibrationPara_IP%d.txt",ip, fileId);
	ofstream parafn(calibrationfn);
	pd1[i].read(infn);
	pede[i].setup(pedefn);
	pd1[i].getFrame(frameId[i]); 
	pede[i].subPede(pd1[i].frameDat);

	for(int k=0;k<nCh;k++){
		if(k<nCh/2){
			wframe.loadData2tmpHist2D(pd1[i].frameDat+k*72*72,k+nCh/2);
		}else{
			wframe.loadData2tmpHist2D(pd1[i].frameDat+k*72*72,nCh-k-1);	
		}
	}
	for(int k=0; k<nCh;k++){
		average[i*nCh+k] = wframe.averageOftmpHist2D(k,maxPixelSignal,minPixelSignal);
		parafn << average[0]/average[i*nCh+k]<<"\t";
	}	
	parafn.close();
}

	return 0;
}
