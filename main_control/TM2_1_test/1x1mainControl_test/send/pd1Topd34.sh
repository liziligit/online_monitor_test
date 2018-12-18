fileId=$1
polNId=$2
pedeId=$3
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Calibration number is empty
fi
if [ "$3" = "" ]
then
  echo Pedestal number is empty
  exit	
fi



set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./pd1Topd3_send.sh ${Id} ${fileId} ${polNId} ${pedeId}
done
