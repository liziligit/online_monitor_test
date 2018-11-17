script_BM=../script_bm
cd ../daq
echo Send Start Signal
./mytcp -c start.c 192.168.2.3
cd ${script_BM}
