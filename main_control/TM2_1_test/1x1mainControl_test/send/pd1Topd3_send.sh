ip=$1
fileId=$2
polNId=$3
pedeId=$4
if [ "$1" = "" ]
then
  echo IP number is empty
fi
if [ "$2" = "" ]
then
  echo Data number is empty
fi
if [ "$3" = "" ]
then
  echo Calibration number is empty
fi
if [ "$4" = "" ]
then
  echo Pedestal number is empty
  exit	
fi


echo ./send -IP ${ip} -cmd "./pd1Topd3.sh ${fileId} ${polNId} ${pedeId} "
./send -IP ${ip} -cmd "./pd1Topd3.sh ${fileId} ${polNId} ${pedeId} "
