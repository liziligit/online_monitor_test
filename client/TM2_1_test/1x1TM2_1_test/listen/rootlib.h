#ifndef _ROOTLIB_
#define _ROOTLIB_
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TROOT.h>
#include <TMath.h>
#include <TParameter.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <TString.h>
#include <TVirtualFFT.h>
#include <TRandom.h>
#include <TStyle.h>
#include <TPad.h>
#include <TPaveStats.h>
#include <TApplication.h>
#include <TF1.h>


using namespace std;

class plot{
public:

TH1D **h1;
TCanvas *c;
TPad *pad;

int nTH1D;
int xbin;
int nColCanvas;
int nRowCanvas;
double max1d;
double min1d; 
double minYd;
double maxYd;

plot(){
h1=NULL;
}

/*
void draw1D(int ip){
       pad[ip-1]->cd();
	for(int i=0;i<nTH1D;i++){
			h1[(ip-1)*nTH1D+i]->GetYaxis()->SetRangeUser(minYd,maxYd);
		if(i==0){
			h1[(ip-1)*nTH1D+i]->SetLineColor(1);
	                h1[(ip-1)*nTH1D+i]->Draw();
		}else{
			h1[(ip-1)*nTH1D+i]->SetLineColor(2);
			h1[(ip-1)*nTH1D+i]->Draw("same");		
		}

	}
		pad[ip-1]->Modified();
                pad[ip-1]->Update();
}*/ 

void draw1D(){
	for(int i=0;i<nTH1D;i++){
			h1[i]->GetYaxis()->SetRangeUser(minYd,maxYd);
		if(i==0){
			h1[i]->SetLineColor(1);
	                h1[i]->Draw();
		}else{
			h1[i]->SetLineColor(2);
			h1[i]->Draw("same");		
		}

	}
		pad->Modified();
                pad->Update();
} 

void loadData2Hist1D(float *data, int iTime, int nChip,int nPixRow ){
        int dataSize, offset;
	dataSize=nChip*nPixRow;
	offset=iTime*dataSize;
	for(int i=0;i<dataSize;i++){
		if(i<dataSize/2){
			h1[iTime]->SetBinContent(i+1+dataSize/2,data[i+offset]);
		}
		else{
			h1[iTime]->SetBinContent(dataSize-i,data[i+offset]);
		}
		
	}
}


/*
void setupCanvas(int nCol_,int nRow_,int xrange=1200,int yrange=800){
TApplication* theApp = new TApplication("App", 0, 0);
nColCanvas=nCol_;
nRowCanvas=nRow_;
c=new TCanvas("Average Data","Average Data",200,10,xrange,yrange);
c->Connect("Closed()", "TApplication", theApp, "Terminate()");
string padName;
pad=new TPad*[nColCanvas*nRowCanvas];
for(int i=0;i<nColCanvas*nRowCanvas;i++){
        padName ="pad"; padName += i;
        pad[i] = new TPad(padName.c_str(), padName.c_str(), 0.02+0.5*(i%nColCanvas), 0.52-0.5*(i/nColCanvas), 0.48+0.5*(i%nColCanvas), 0.98-0.5*(i/nColCanvas));
	pad[i]->Draw();                                      
}

}*/


void setupCanvas(int nCol_,int nRow_, int ip, int xrange=1200,int yrange=800){
TApplication* theApp = new TApplication("App", 0, 0);
nColCanvas=nCol_;
nRowCanvas=nRow_;
int i;
i=ip-1;
int xTop = (0.02+0.5*(i%nColCanvas))*xrange;
int yTop = (0.02+0.5*(i/nColCanvas))*yrange;
int ww = xrange/2;
int wh = yrange/2;
char canvasName[100];
sprintf(canvasName,"Average Data %d", ip);
c=new TCanvas(canvasName, canvasName, xTop, yTop, ww, wh);
c->Connect("Closed()", "TApplication", theApp, "Terminate()");
pad = new TPad();
pad->Draw();
}

void setupTH1D(int nCol_,int nRow_, int nTH1D_, int xbin_,double min1d_,double max1d_, string hn){

nColCanvas=nCol_;
nRowCanvas=nRow_;
nTH1D=nTH1D_;
xbin=xbin_;

min1d=min1d_;
max1d=max1d_;


string histName;
        h1=new TH1D*[nTH1D*nColCanvas*nRowCanvas];
	for(int i=0;i<nTH1D*nColCanvas*nRowCanvas;i++){
        histName = hn; histName += i;
        h1[i] = new TH1D(histName.c_str(), histName.c_str(), xbin, min1d, max1d);
	h1[i]->SetStats(0);
	}

}

void setupYMinMax(double min_,double max_){
minYd=min_;
maxYd=max_;
}

void delete1D(){


	for(int i=0;i<nTH1D*nColCanvas*nRowCanvas;i++){
        delete h1[i];
	}
	delete [] h1;
	h1=NULL;
}

};

class processPara{
	public:

		int nChip;
		int nRow;
		int nTimes;
		plot pt;
		int IP;

	    	char *buf;
	    	int listenfd, connectfd;  /* socket descriptors */
	    	struct sockaddr_in server; /* server's address information */
	    	struct sockaddr_in client; /* client's address information */
	    	socklen_t addrlen;
};

#endif
