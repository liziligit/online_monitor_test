ip=$1
fileIdStart=$2
fileIdEnd=$3
sampleFlag=$4

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
  echo Sample flag is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./runData.sh ${fileIdStart} ${fileIdEnd} ${sampleFlag}"
./send -IP ${ip} -cmd "./runData.sh ${fileIdStart} ${fileIdEnd} ${sampleFlag}"
