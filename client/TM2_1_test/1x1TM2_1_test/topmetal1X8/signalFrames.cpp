//find signal frames from all frames 
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

pd1Pede pede;
placData_1 pd1;
char infn[100];
char pedefn[100];
char canvasfn[100];
sprintf(infn,"%s_%d.pd1",infile, fileId);
sprintf(pedefn,"%s_%d", pedefile, pedeId);
sprintf(canvasfn,"../result/pd1/sumPerFrame_%d.png",fileId);	
pd1.read(infn);
pede.setup(pedefn);
int nCh=pd1.adcCha();
int nPix=pd1.nPix();
printf("nCh: %d, nPix: %d\n", nCh, nPix);


signalFrameFinder  signalFinder;
signalFinder.setupCanvas();

for(int i=0;i<pd1.nFrame();i++){
pd1.getFrame(i);  // 输入帧数和adc通道数，不加adc通道数这个参数，会获取所有通道的数据
pede.subPede(pd1.frameDat);  //subtract pede 不加第二个参数，会操作所有通道的数据
signalFinder.sum(pd1.frameDat, nCh*nPix);
signalFinder.fillTH1();
signalFinder.frameFinder(1e6,i);
}
signalFinder.startEndFrameFinder();
signalFinder.print(signalFinder.signalFrame);
//signalFinder.print(signalFinder.startFrame);
//signalFinder.print(signalFinder.endFrame);
signalFinder.draw(canvasfn);
printf("%d\n",signalFinder.start);
return 0;
}
