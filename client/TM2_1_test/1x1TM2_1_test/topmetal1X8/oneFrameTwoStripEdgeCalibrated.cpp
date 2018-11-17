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
char canvas2Dfn[100];
char canvas1Dfn[100];
sprintf(canvas2Dfn,"../result/pd1/dim%d_frame%d-%dedgeCalibrated_file%d.png",dimId, frame1Id, frame2Id, fileId);
sprintf(canvas1Dfn,"../result/pd1/dim%d_projection%d-%dedgeCalibrated_file%d.png",dimId, frame1Id, frame2Id, fileId);
char edgeCalibrationfn[100];
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
double *edgeCalibratedPara;
edgeCalibratedPara = new double[nPix];
sprintf(edgeCalibrationfn,"../data/tauData/edgeCalibrationPara.txt");
ifstream edgeCalibratedParafn(edgeCalibrationfn);
for(int k=0;k<nPix;k++){
	edgeCalibratedParafn >> edgeCalibratedPara[k];
}
edgeCalibratedParafn.close();
int xbin,ybin;
xbin=68+nCh*nPix+(nCh-1)*64;
ybin=nPix;
wholeFrame wframe;
wframe.setupCanvas2D();
wframe.setupCanvas1D();
wframe.setupHist2D(xbin,ybin);
wframe.setup2DMinMax(minPixelSignal, maxPixelSignal);
wframe.setuptmpHist2D(nCh,1,nPix,nPix,"hist2d");
for(int i=0; i<nStrip; i++){
	if(dimId==1){
	ip=3+(dimId+i-1)*4;
	}
	if(dimId==2){
	ip=3+(dimId+i)*4;
	}
	sprintf(infn,"%sIP%d/beam_%d.pd1",infile, ip, fileId);
	sprintf(pedefn,"%sIP%d/pede_%d", pedefile, ip, pedeId);	

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
	
	wframe.loadtmpHist2HistEdgeCalibrated(ip, edgeCalibratedPara);
	
}
wframe.draw2D(canvas2Dfn);
wframe.setupHist1D();
wframe.draw1D(canvas1Dfn);
	return 0;
}
