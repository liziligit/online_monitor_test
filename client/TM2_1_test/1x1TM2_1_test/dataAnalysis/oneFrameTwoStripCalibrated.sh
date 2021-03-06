fileId=$1
pedeId=$2
dimId=$3
frame1Id=$4
frame2Id=$5
lowLimitPixel=$6 # minimum signal value of pixel 
upLimitPixel=$7  # maximum signal value of pixel 


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
  echo Dimension number is empty
fi
if [ "$4" = "" ]
then
  echo Frame1 number is empty
fi
if [ "$5" = "" ]
then
  echo Frame2 number is empty
fi

if [ "$6" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$7" = "" ]
then
  echo TH2D Max Range is empty
  exit
fi

data_analysis=../dataAnalysis
cd ${data_analysis}


dataFile=../data/runData/
pedeFile=../data/pedeData/
cppPath=../topmetal1X8

cd ${cppPath}
g++ -o oneFrameTwoStripCalibrated  oneFrameTwoStripCalibrated.cpp `root-config --cflags` `root-config --glibs`
./oneFrameTwoStripCalibrated ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${dimId} ${frame1Id}  ${frame2Id} ${upLimitPixel} ${lowLimitPixel} 

cd ${data_analysis}

outFilePath=../result/pd1

eog ${outFilePath}/dim${dimId}_frame${frame1Id}-${frame2Id}Calibrated_file${fileId}.png
eog ${outFilePath}/dim${dimId}_projection${frame1Id}-${frame2Id}Calibrated_file${fileId}.png

