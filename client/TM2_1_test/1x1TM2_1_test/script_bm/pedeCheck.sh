fileIdStart=$1
let fileIdEnd=${fileIdStart}+1

if [ "$1" = "" ]
then
  echo Pedestal number is empty 
  exit	
fi

#sampleBytes=$2 # small: 45M = 47185920;
sampleBytes=47185920
lowLimitPixel=-10
upLimitPixel=10
displayMode=2
script_BM=../script_bm
cd ${script_BM}
pedeCheck=../data/pedeData/pedeCheck


if [ -f "${pedeCheck}_${fileIdStart}.pd1" ]; 
then 
rm -f ${pedeCheck}_${fileIdStart}.pd1
echo delete==========  ${pedeCheck}_${fileIdStart}.pd1       	 
fi 




cd ../daq


# if realTime.c is changed, we need to recompile this file to generate readDdrContinue.ce using ./mytcp -c realTime.c in ../daq	
echo ./realTime.ce  -fn ${pedeCheck} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes} -displayMode ${displayMode}
./realTime.ce  -fn ${pedeCheck} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd}  -sampleBytes ${sampleBytes} -displayMode ${displayMode}

pede=../data/pedeData/pede
cppPath=../topmetal1X8 

outFilePath=../result/pd1/

root -L  -l -q  "${cppPath}/pedeCheck.cpp++(\"${pedeCheck}_${fileIdStart}.pd1\",\"${pede}_${fileIdStart}\",\"${outFilePath}\",${lowLimitPixel},${upLimitPixel})" 

 
eog   ${outFilePath}/noise.png 

