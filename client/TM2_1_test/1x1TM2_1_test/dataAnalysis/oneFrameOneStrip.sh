fileId=$1
pedeId=$2
frameId=$3
lowLimitPixel=$4 # minimum signal value of pixel 
upLimitPixel=$5  # maximum signal value of pixel 


if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Pedestal number is empty
fi
if [ "$3" = "" ]
then
  echo Frame number is empty
fi
if [ "$4" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$5" = "" ]
then
  echo TH2D Max Range is empty
  exit
fi

data_analysis=../dataAnalysis
cd ${data_analysis}


dataFile=../data/runData/beam
pedeFile=../data/pedeData/pede
cppPath=../topmetal1X8

cd ${cppPath}
g++ -o oneFrameOneStrip  oneFrameOneStrip.cpp `root-config --cflags` `root-config --glibs`
./oneFrameOneStrip ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${frameId} ${upLimitPixel} ${lowLimitPixel} 

cd ${data_analysis}

outFilePath=../result/pd1

eog ${outFilePath}/frame${frameId}_file${fileId}.png


