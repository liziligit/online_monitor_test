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


int pedeCheck(char *fn, char *pedeFile, char *outFilePath,double lowLimitPixel, double upLimitPixel){

	char outfn[100];
	sprintf(outfn,"%s/noise.png",outFilePath);
	cout<<outfn<<endl;	
        pd1Debug pd1d;
        pd1d.read(fn);
        pd1d.noise(pedeFile, outfn, lowLimitPixel, upLimitPixel);
	return 0;
}

