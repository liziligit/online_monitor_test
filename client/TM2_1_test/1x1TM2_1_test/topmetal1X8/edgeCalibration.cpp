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
int ip;
ip = atol(argv[5]);
int iCh;
iCh= atol(argv[6]);
int frameId;
frameId= atol(argv[7]);
double maxPixelSignal;
maxPixelSignal = atof(argv[8]);
double minPixelSignal;
minPixelSignal = atof(argv[9]);

char calibrationfn[100];
pd1Pede pede;
placData_1 pd1;
char infn[100];
char pedefn[100];
int nPix, nCh;
nPix=72;
nCh=8;
wholeFrame wframe;
wframe.setuptmpHist2D(nCh,1,nPix,nPix,"hist2d");
double colAverage[nPix];

sprintf(infn,"%sIP%d/beam_%d.pd1",infile, ip, fileId);
sprintf(pedefn,"%sIP%d/pede_%d", pedefile, ip, pedeId);	
sprintf(calibrationfn,"../data/tauData/edgeCalibrationPara.txt");
ofstream parafn(calibrationfn);
pd1.read(infn);
pede.setup(pedefn);
pd1.getFrame(frameId); 
pede.subPede(pd1.frameDat);

for(int k=0;k<nCh;k++){
	if(k<nCh/2){
		wframe.loadData2tmpHist2D(pd1.frameDat+k*72*72,k+nCh/2);
	}else{
		wframe.loadData2tmpHist2D(pd1.frameDat+k*72*72,nCh-k-1);	
	}
}

for(int i=0;i<nPix;i++){

	colAverage[i]=wframe.colAverageOftmpHist2D(iCh, i, maxPixelSignal, minPixelSignal);
	parafn << colAverage[0]/colAverage[i] <<"\t";
}

parafn.close();


return 0;
}
