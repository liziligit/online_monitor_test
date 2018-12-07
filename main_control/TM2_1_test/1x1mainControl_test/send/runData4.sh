fileIdStart=$1
fileIdEnd=$2
sampleFlag=$3
store_file_name=$4
if [ "$1" = "" ]
then
  echo Data starting number is empty
  exit
fi
if [ "$2" = "" ]
then
  echo Data Ending number is empty
  exit
fi
if [ "$3" = "" ]
then
  echo Sample flag is empty
  exit
fi
if [ "$4" = "" ]
then
  echo store_file_name is empty
  exit
fi

./startTm2-ClearFifo_send.sh
sleep 5

set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./runData_send.sh ${Id} ${fileIdStart} ${fileIdEnd} ${sampleFlag} ${store_file_name}
done
