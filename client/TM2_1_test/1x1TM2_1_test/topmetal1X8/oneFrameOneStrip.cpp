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
int frameId;
frameId= atol(argv[5]);
double maxPixelSignal;
maxPixelSignal = atof(argv[6]);
double minPixelSignal;
minPixelSignal = atof(argv[7]);
pd1Pede pede;
placData_1 pd1;
char infn[100];
char pedefn[100];
char canvasfn[100];
sprintf(infn,"%s_%d.pd1",infile, fileId);
sprintf(pedefn,"%s_%d", pedefile, pedeId);	
sprintf(canvasfn,"../result/pd1/frame%d_file%d.png",frameId, fileId);	
pd1.read(infn);
pede.setup(pedefn);

int nCh=pd1.adcCha();

plot pt;
int ip=1;
pt.setupCanvas(nCh,1, ip); //设置canvas上图片的行数，列数, 及 canvas的位置
pt.setup2D(nCh,1,72,72,"hist2d"); //Tcanvas中的图的行数，列数，阵列的行数，列数，图的名字
pt.setup2DMinMax(minPixelSignal,maxPixelSignal);



pd1.getFrame(frameId);  // 输入帧数和adc通道数，不加adc通道数这个参数，会获取所有通道的数据
pede.subPede(pd1.frameDat);  //subtract pede 不加第二个参数，会操作所有通道的数据

	for(int k=0;k<nCh;k++){
		if(k<nCh/2){
			pt.loadData2Hist2D(pd1.frameDat+k*72*72,k+nCh/2);
		}else{
			pt.loadData2Hist2D(pd1.frameDat+k*72*72,nCh-k-1);	
		}
	}




pt.draw2D(canvasfn);  //要画图的数据，阵列的行数，列数






	return 0;
}
