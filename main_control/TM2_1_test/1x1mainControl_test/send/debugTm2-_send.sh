ip=$1
if [ "$1" = "" ]
then
  echo IP number is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./debugTm2-.sh"
./send -IP ${ip} -cmd "./debugTm2-.sh"

