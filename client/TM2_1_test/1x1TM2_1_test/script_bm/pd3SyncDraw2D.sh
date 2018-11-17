fileId=$1
lowLimitPixel=$2 # minimum signal value of pixel 
upLimitPixel=$3  # maximum signal value of pixel 
ip=$4
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$3" = "" ]
then
  echo TH2D Max Range is empty
fi

if [ "$4" = "" ]
then
  echo IP number is empty
  exit
fi




script_BM=../script_bm
cd ${script_BM}


dataFile=../data/runData/beam
cppPath=../topmetal1X8

cd ${cppPath}

g++ -o pd3_syncDraw2D  pd3_syncDraw2D.cpp `root-config --cflags` `root-config --glibs`
./pd3_syncDraw2D ${dataFile} ${fileId}  ${upLimitPixel} ${lowLimitPixel} ${ip}
cd ${script_BM}



