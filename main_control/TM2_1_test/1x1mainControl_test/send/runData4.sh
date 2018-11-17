fileIdStart=$1
fileIdEnd=$2
sampleFlag=$3
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

./startTm2-ClearFifo_send.sh
sleep 1
set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./runData_send.sh ${Id} ${fileIdStart} ${fileIdEnd} ${sampleFlag}
done
