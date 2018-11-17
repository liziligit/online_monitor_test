fileIdStart=$1
fileIdEnd=$2
pedeId=$3
sampleBytes=$4  # small: 45M = 47185920; large: 485M = 508559360
ip=$5
displayMode=1 ### online pd1 

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
  echo Pedestal number is empty
fi

if [ "$4" = "" ]
then
  echo sampleBytes is empty
fi

if [ "$5" = "" ]
then
  echo IP number is empty
  exit
fi

script_BM=../script_bm
cd ../daq


echo data acquisition

# if realTime.c is changed, we need to recompile this file to generate readDdrContinue.ce using ./mytcp -c realTime.c in ../daq	
echo ./realTime.ce -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes}  -displayMode ${displayMode} -pedeId ${pedeId} -IP ${ip}
./realTime.ce   -fileStart ${fileIdStart} -fileEnd ${fileIdEnd} -sampleBytes ${sampleBytes} -displayMode ${displayMode} -pedeId ${pedeId} -IP ${ip}
	

cd ${script_BM}


