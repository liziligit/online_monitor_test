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


int getCharge(char *polNPath,char *InPolNName,char *InPolNRevName,int polNDataID = 0,char *dataPath=" ",char *InDataName=" ",char *pedePath="",char *pedefile="",int pedeID=0,char *inDataType = "pd1",char* outDataType="pd3", int dataID = 0){
	char polPar[100];
	sprintf(polPar,"%s/%s%d.txt",polNPath,InPolNName,polNDataID);
//	cout<<polPar<<endl;
	char polParRev[100];
	sprintf(polParRev,"%s/%s%d.txt",polNPath,InPolNRevName,polNDataID);
//	cout<<polParRev<<endl;
	char pedeFile[100];//pede input
	sprintf(pedeFile,"%s/%s%d",pedePath,pedefile,pedeID);//pede input
//	cout<<pedeFile<<endl;
	char polNCharge[100];
	sprintf(polNCharge,"%s/polNCharge%d.txt",dataPath,dataID);
	char Input[100];
	sprintf(Input,"%s/%s%d.%s",dataPath,InDataName,dataID,inDataType);
//	cout<<Input<<endl;
	char pointChargeFile[100];
	sprintf(pointChargeFile,"%s/pointCharge%d.txt",dataPath,dataID);
	char pointChargeRootFile[100];
	sprintf(pointChargeRootFile,"%s/pointChargeRoot%d.root",dataPath,dataID);
	char pointChargeCanvasRootFile[100];
	sprintf(pointChargeCanvasRootFile,"%s/pointChargeCanvas%d.root",dataPath,dataID);

	
	char outPlacData3[100];
	sprintf(outPlacData3,"%s/%s%d.%s",dataPath,InDataName,dataID,outDataType);
//	cout<<outPlacData3<<endl;
	placData_1 pd1;	

	polNGetCharge polNGetChargeObj;
	pd1.read(Input);
	cout<<"pd1.p"<<(int*)(pd1.p)[100]<<endl;
	polNGetChargeObj.setup(&pd1);

        polNGetChargeObj.run(pedeFile,polPar,polParRev,polNCharge,outPlacData3,pointChargeFile,pointChargeRootFile,pointChargeCanvasRootFile);


	return 0;
}
