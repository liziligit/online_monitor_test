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

int pd3_drawPixel(char *fn, char *outFilePath, int ich, int ipixel){
	char outfn[100];
	sprintf(outfn,"%s/signalChip%dPixel%d.png",outFilePath,ich,ipixel);
	cout<<outfn<<endl;
	pd3Debug pd3d;
	pd3d.read(fn);
	pd3d.drawPixelDebug(outfn, ich, ipixel);



      return 0;
}
