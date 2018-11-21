ip=$1
pedeId=$2
if [ "$1" = "" ]
then
  echo IP number is empty
fi
if [ "$2" = "" ]
then
  echo pedeId is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./pedeCheck.sh ${pedeId}"
./send -IP ${ip} -cmd "./pedeCheck.sh ${pedeId}"
