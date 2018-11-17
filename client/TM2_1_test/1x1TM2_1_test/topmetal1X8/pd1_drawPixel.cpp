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

int pd1_drawPixel(char *fn, char *outFilePath, int ich, int ipixel){
	char outfn[100];
	sprintf(outfn,"%s/decayChip%dPixel%d.png",outFilePath,ich,ipixel);
	cout<<outfn<<endl;
	pd1Debug pd1d;
	pd1d.read(fn);
	pd1d.drawPixelDebug(outfn, ich, ipixel);
	pd1d.readHeaders();


      return 0;
}
