ip=$1
polNId=$2
if [ "$1" = "" ]
then
  echo IP number is empty
fi
if [ "$2" = "" ]
then
  echo polNId is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./tau.sh ${polNId}"
./send -IP ${ip} -cmd "./tau.sh ${polNId}"
