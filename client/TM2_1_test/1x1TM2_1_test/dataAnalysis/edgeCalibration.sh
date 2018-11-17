fileId=$1
pedeId=$2
IP=$3
iChip=$4
frameId=$5
lowLimitPixel=$6 # minimum signal value of normal pixel  100 
upLimitPixel=$7  # maximum signal value of normal pixel  1200


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
  echo IP number is empty
fi
if [ "$4" = "" ]
then
  echo Chip number is empty
fi
if [ "$5" = "" ]
then
  echo Frame number is empty
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
g++ -o edgeCalibration  edgeCalibration.cpp `root-config --cflags` `root-config --glibs`
./edgeCalibration ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${IP} ${iChip}  ${frameId} ${upLimitPixel} ${lowLimitPixel} 

cd ${data_analysis}






