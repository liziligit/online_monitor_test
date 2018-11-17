fileId=$1
if [ "$1" = "" ]
then
  echo Pedestal number is empty
  exit
fi
#sampleBytes=$2 # small: 45M = 47185920;
#lowLimitPixel=$3
#upLimitPixel=$4
sampleBytes=47185920
lowLimitPixel=-10
upLimitPixel=10
IPStart=3
IPEnd=15
script_BM=../script_bm
cd ${script_BM}
pedeCheck=../data/pedeData/pedeCheckIP

set IP=0

for((IP=${IPStart};IP<=${IPEnd};IP++))
do
	if [ -f "${pedeCheck}${IP}_${fileId}.pd1" ]; 
	then 
        rm -f ${pedeCheck}${IP}_${fileId}.pd1
        echo delete==========  ${pedeCheck}${IP}_${fileId}.pd1       	 
	fi 
       IP=${IP}+3
done



cd ../daq

echo Send Start Signal
./mytcp -c start.c 192.168.2.15

./readDdrContinue.ce -fn ${pedeCheck} -fileId ${fileId} -sampleBytes ${sampleBytes} 

pede=../data/pedeData/pedeIP
cppPath=../topmetal1X8 

outFilePath=../result/pd1/

for((IP=${IPStart};IP<=${IPEnd};IP++))
do
	root -L  -l -q  "${cppPath}/pedeCheck.cpp++(\"${pedeCheck}${IP}_${fileId}.pd1\",\"${pede}${IP}_${fileId}\",\"${outFilePath}\",${IP},${lowLimitPixel},${upLimitPixel})" 
       
	IP=${IP}+3
done
 
for((IP=${IPStart};IP<=${IPEnd};IP++))
do
        eog   ${outFilePath}/noiseIP${IP}.png 
	IP=${IP}+3
done 

