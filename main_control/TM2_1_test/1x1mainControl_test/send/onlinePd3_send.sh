ip=$1
fileIdStart=$2
fileIdEnd=$3
pedeId=$4
polNId=$5
sampleBytes=$6

if [ "$1" = "" ]
then
  echo IP number is empty
fi
if [ "$2" = "" ]
then
  echo Data starting number is empty
fi
if [ "$3" = "" ]
then
  echo Data Ending number is empty
fi
if [ "$4" = "" ]
then
  echo Pedestal number is empty
fi
if [ "$5" = "" ]
then
  echo PolN number is empty
fi
if [ "$6" = "" ]
then
  echo sampleBytes is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./onlinePd3.sh ${fileIdStart} ${fileIdEnd} ${pedeId} ${polNId} ${sampleBytes} ${ip}"
./send -IP ${ip} -cmd "./onlinePd3.sh ${fileIdStart} ${fileIdEnd} ${pedeId} ${polNId} ${sampleBytes} ${ip}"
