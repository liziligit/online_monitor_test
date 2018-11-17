Vreset=$1
Vref=$2
script_BM=../script_bm
cd ../daq
./tm2-Config.sh ${Vreset} ${Vref}
cd ${script_BM}


