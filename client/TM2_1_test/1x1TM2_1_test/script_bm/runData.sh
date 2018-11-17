fileIdStart=$1
fileIdEnd=$2
sampleFlag=$3
displayMode=3 ### 2 save all channel pd1 file   3 save 0 channel pd1 file
#sampleBytes=$3  # small: 45M = 47185920; large: 485M = 508559360
if [ "$1" = "" ]
then
  echo Data starting number is empty
fi
if [ "$2" = "" ]
then
  echo Data Ending number is empty
fi
if [ "$3" = "" ]
then
  echo Sample flag is empty
  exit
fi
if [ "${sampleFlag}" = "s" ];
	then
	sampleBytes=47185920;
elif [ "${sampleFlag}" = "l" ];
	then
	sampleBytes=508559360;
else
	echo unknown sample flag
	exit
fi

script_BM=../script_bm
cd ../daq



runData=../data/runData/beam

echo data acquisition

# if realTime.c is changed, we need to recompile this file to generate readDdrContinue.ce using ./mytcp -c realTime.c in ../daq	
echo ./realTime.ce  -fn ${runData} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes}  -displayMode ${displayMode}
./realTime.ce  -fn ${runData} -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes} -displayMode ${displayMode}
	

cd ${script_BM}


