
fileId=$1
ich=$2
ipixel=$3
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Chip ID is empty
fi
if [ "$3" = "" ]
then
  echo Pixel ID is empty
  exit
fi

script_BM=../script_bm
cd ${script_BM}
dataFile=../data/runData/beam
cppPath=../topmetal1X8

outFilePath=../result/pd3


echo root  -L -l  -q "${cppPath}/pd3_drawPixel.cpp++(\"${dataFile}_${fileId}.pd3\", \"${outFilePath}\", ${ich}, ${ipixel})" 
root  -L -l  -q "${cppPath}/pd3_drawPixel.cpp++(\"${dataFile}_${fileId}.pd3\", \"${outFilePath}\", ${ich}, ${ipixel})" 




eog   ${outFilePath}/signalChip${ich}Pixel${ipixel}.png 

 
