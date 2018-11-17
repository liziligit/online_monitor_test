ip=$1
if [ "$1" = "" ]
then
  echo IP number is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./compileRealTime.sh"
./send -IP ${ip} -cmd "./compileRealTime.sh"
