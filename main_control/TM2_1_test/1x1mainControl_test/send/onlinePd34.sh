fileIdStart=$1
fileIdEnd=$2
pedeId=$3
polNId=$4
sampleBytes=$5

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
  echo PolN number is empty
fi
if [ "$5" = "" ]
then
  echo sampleBytes is empty
  exit
fi



./startTm2-ClearFifo_send.sh
sleep 1
set Id=0
for((Id=1;Id<=4;Id++))
do
	 ./onlinePd3_send.sh ${Id} ${fileIdStart} ${fileIdEnd} ${pedeId} ${polNId} ${sampleBytes}
done
