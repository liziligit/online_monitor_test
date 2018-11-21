ip=$1
fileIdStart=$2
fileIdEnd=$3
sampleFlag=$4
store_file_name=$5

if [ "$1" = "" ]
then
  echo IP number is empty
  exit
fi
if [ "$2" = "" ]
then
  echo Data starting number is empty
  exit
fi
if [ "$3" = "" ]
then
  echo Data Ending number is empty
  exit
fi
if [ "$4" = "" ]
then
  echo Sample flag is empty
  exit
fi
if [ "$5" = "" ]
then
  echo store_file_name is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./runData.sh ${fileIdStart} ${fileIdEnd} ${sampleFlag} ${store_file_name}"
./send -IP ${ip} -cmd "./runData.sh ${fileIdStart} ${fileIdEnd} ${sampleFlag} ${store_file_name}"
