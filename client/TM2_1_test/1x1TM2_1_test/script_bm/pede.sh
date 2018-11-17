fileIdStart=$1
let fileIdEnd=${fileIdStart}+1

if [ "$1" = "" ]
then
  echo Pedestal number is empty 
  exit	
fi


#sampleBytes=$2 # small: 45M = 47185920;
#sampleBytes=47185920
sampleBytes=1718592
script_BM=../script_bm
cd ${script_BM}
pedeDataChar=pede
pedeDataPathLocal=../data/pedeData

cd ../daq

pede=../data/pedeData/pede
#displayMode=2 ### save pd1 file
displayMode=3 ### save pd1 file for 0 channel

# if realTime.c is changed, we need to recompile this file to generate readDdrContinue.ce using ./mytcp -c realTime.c in ../daq	
echo ./realTime.ce  -fn ${pede} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes} -displayMode ${displayMode}
./realTime.ce  -fn ${pede} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd}  -sampleBytes ${sampleBytes} -displayMode ${displayMode}
	

cd ../topmetal1X8


echo root -L -l -q -b "pede.cpp++(\"${pedeDataPathLocal}\",\"${pedeDataChar}_\",${fileIdStart})"
root -L -l -q -b "pede.cpp++(\"${pedeDataPathLocal}\",\"${pedeDataChar}_\",${fileIdStart})"


cd ${script_BM}
