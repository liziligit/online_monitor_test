fileId=$1
pedeId=$2
dimId=$3
frame1IdStart=$4
frame2IdStart=$5
nFrame=$6
lowLimitPixel=$7 # minimum signal value of pixel 
upLimitPixel=$8  # maximum signal value of pixel 


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
  echo Frame1 start number is empty
fi
if [ "$5" = "" ]
then
  echo Frame2 start number is empty
fi
if [ "$6" = "" ]
then
  echo frame numbers
fi
if [ "$7" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$8" = "" ]
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
g++ -o oneFrameTwoStrip  oneFrameTwoStrip.cpp `root-config --cflags` `root-config --glibs`

set iframe=0
for((iframe=0;iframe<=${nFrame};iframe++))
do
let frame1Id=${frame1IdStart}+iframe
let frame2Id=${frame2IdStart}+iframe
./oneFrameTwoStrip ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${dimId} ${frame1Id}  ${frame2Id} ${upLimitPixel} ${lowLimitPixel} 
done


cd ${data_analysis}


