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
	char *fn;
	fn = argv[1];
	int fileId;
	fileId = atol(argv[2]);
	double maxPixelSignal;
	maxPixelSignal = atof(argv[3]);
	double minPixelSignal;
	minPixelSignal = atof(argv[4]);
	int ip;
	ip = atoi(argv[5]);
	placData_3 pd3;
	char infn[100];	
	sprintf(infn,"%s_%d.pd3",fn, fileId);
	pd3.read(infn);

	int nCh=pd3.adcCha();
	plot pt;
	pt.setupCanvas(nCh,1, ip); //设置canvas上图片的行数，列数, 及canvas的位置
	pt.setup2D(nCh,1,72,72,"hist2d"); //Tcanvas中的图的行数，列数，阵列的行数，列数，图的名字
	pt.setup2DMinMax(minPixelSignal,maxPixelSignal);
	int ch;
	for(int i=0;i<pd3.nFrame();i++){
	if(kbhit())
	{

	ch=getch();
	if(ch==27) break;// esc == 27
	}

//	if(i%10==0){
	cout<<i<<endl;


	pd3.getFrame(i);  // 输入帧数和adc通道数，不加adc通道数这个参数，会获取所有通道的数据


	for(int k=0;k<nCh;k++){
		if(k<nCh/2){
			pt.loadData2Hist2D(pd3.frameDat+k*72*72,k+nCh/2);
		}else{
			pt.loadData2Hist2D(pd3.frameDat+k*72*72,nCh-k-1);	
		}
	}



	pt.draw2D();  //要画图的数据，阵列的行数，列数

//	}

	}


	cout<<"end"<<endl;

	return 0;
}
