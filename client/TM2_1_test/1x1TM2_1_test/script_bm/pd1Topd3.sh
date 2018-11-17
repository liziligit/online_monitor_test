fileId=$1
polNId=$2
pedeId=$3
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Calibration number is empty
fi
if [ "$3" = "" ]
then
  echo Pedestal number is empty
  exit	
fi

script_BM=../script_bm
cd ${script_BM}
dataPath=../data/runData
dataName=beam

guardRingDataPath=../data/tauData
proPath=../topmetal1X8
polNParChar=polNPar
polNParCharRev=polNParRev

pedePath=../data/pedeData
pedeFile=pede




echo root -L -l -q -b  "${proPath}/getCharge.cpp++(\"${guardRingDataPath}\",\"${polNParChar}_\",\"${polNParCharRev}_\",${polNId},\"${dataPath}\",\"${dataName}_\",\"${pedePath}\",\"${pedeFile}_\",${pedeId},\"pd1\",\"pd3\",${fileId})" 
root -L -l -q -b  "${proPath}/getCharge.cpp++(\"${guardRingDataPath}\",\"${polNParChar}_\",\"${polNParCharRev}_\",${polNId},\"${dataPath}\",\"${dataName}_\",\"${pedePath}\",\"${pedeFile}_\",${pedeId},\"pd1\",\"pd3\",${fileId})"	





cd ${script_BM}
