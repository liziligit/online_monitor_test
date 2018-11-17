#include "tcp_server.h"
int main(int argc, char *argv[])
{

int ip;
ip = atoi(argv[1]);
double min;
min = atof(argv[2]);
double max;
max = atof(argv[3]);


tcp_server ts;
ts.setup(1234);
processPara  para;
int nChip, nRow, nTimes;
nChip=8;
nRow=72;
nTimes=2;
plot pt;
pt.setupCanvas(2,2,ip);
pt.setupTH1D(1,1,nTimes,nChip*nRow,0,nChip*nRow,"AverageData");
pt.setupYMinMax(min,max);

para.nChip=nChip;
para.nRow=nRow;
para.nTimes=nTimes;
para.pt=pt;
para.buf=ts.buf;
para.listenfd=ts.listenfd;
para.connectfd=ts.connectfd;
para.server=ts.server;
para.client=ts.client;
para.addrlen=ts.addrlen;
recv_msg((void*)(&para));

return 0;
}
