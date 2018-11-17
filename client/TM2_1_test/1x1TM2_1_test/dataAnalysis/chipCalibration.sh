fileId=$1
pedeId=$2
dimId=$3
frame1Id=$4
frame2Id=$5
lowLimitPixel=$6 # minimum signal value of normal pixel  500 
upLimitPixel=$7  # maximum signal value of normal pixel  1800


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
  echo Normal pixel min is empty
fi

if [ "$7" = "" ]
then
  echo Normal pixel max is empty
  exit
fi

data_analysis=../dataAnalysis
cd ${data_analysis}


dataFile=../data/runData/
pedeFile=../data/pedeData/
cppPath=../topmetal1X8

cd ${cppPath}
g++ -o chipCalibration  chipCalibration.cpp `root-config --cflags` `root-config --glibs`
./chipCalibration ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${dimId} ${frame1Id}  ${frame2Id} ${upLimitPixel} ${lowLimitPixel} 

cd ${data_analysis}






