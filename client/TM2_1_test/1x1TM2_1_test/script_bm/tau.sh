polNId=$1
fileIdStart=${polNId}
let fileIdEnd=${fileIdStart}+1
if [ "$1" = "" ]
then
  echo Calibration number is empty
  exit
fi
#sampleBytes=$2 # small: 45M = 47185920;
sampleBytes=47185920
script_BM=../script_bm
cd ${script_BM}

guardRingDataPath=../data/tauData
proPath=../topmetal1X8
guardRingDataChar=tau



cd ../daq


tauData=../data/tauData/tau


displayMode=2 ### save pd1 file

# if realTime.c is changed, we need to recompile this file to generate readDdrContinue.ce using ./mytcp -c realTime.c in ../daq	
echo ./realTime.ce  -fn ${tauData} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes} -displayMode ${displayMode}
./realTime.ce  -fn ${tauData} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd}  -sampleBytes ${sampleBytes} -displayMode ${displayMode}

cd ${script_BM}

echo root -L -l -q -b  "${proPath}/getPolNPar.cpp++(\"${guardRingDataPath}\",\"${guardRingDataChar}\",\"pd1\",${polNId})" 
root -L -l -q -b  "${proPath}/getPolNPar.cpp++(\"${guardRingDataPath}\",\"${guardRingDataChar}\",\"pd1\",${polNId})" 





