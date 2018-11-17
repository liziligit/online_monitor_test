fileId=$1
pedeId=$2
lowLimitPixel=$3 # minimum signal value of pixel 
upLimitPixel=$4  # maximum signal value of pixel 
ip=$5

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
  echo TH2D Min Range is empty
fi

if [ "$4" = "" ]
then
  echo TH2D Max Range is empty
fi

if [ "$5" = "" ]
then
  echo IP number is empty
  exit
fi

script_BM=../script_bm
cd ${script_BM}


dataFile=../data/runData/beam
pedeFile=../data/pedeData/pede
cppPath=../topmetal1X8

cd ${cppPath}
g++ -o pd1_syncDraw2D  pd1_syncDraw2D.cpp `root-config --cflags` `root-config --glibs`
./pd1_syncDraw2D ${dataFile} ${fileId} ${pedeFile} ${pedeId} ${upLimitPixel} ${lowLimitPixel} ${ip}
#root  -L -l -q  "${cppPath}/pd1_syncDraw2D.cpp++(\"${dataFile}\", ${fileId}, \"${pedeFile}\", ${pedeId}, ${upLimitPixel}, ${lowLimitPixel})" 	
cd ${script_BM}


