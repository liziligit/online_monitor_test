#### find signal frames from all frames ####
fileId=$1
pedeId=$2


if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Pedestal number is empty
  exit
fi


data_analysis=../dataAnalysis
cd ${data_analysis}


dataFile=../data/runData/beam
pedeFile=../data/pedeData/pede
cppPath=../topmetal1X8
outFilePath=../result/pd1

cd ${cppPath}
g++ -o signalFrames  signalFrames.cpp `root-config --cflags` `root-config --glibs`
./signalFrames ${dataFile} ${fileId} ${pedeFile} ${pedeId}
cd ${data_analysis}

eog ${outFilePath}/sumPerFrame_${fileId}.png
