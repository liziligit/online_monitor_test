ip=$1
Vreset=$2
Vref=$3
if [ "$1" = "" ]
then
  echo IP number is empty
fi
if [ "$2" = "" ]
then
  echo CSA Vreset is empty
fi
if [ "$3" = "" ]
then
  echo CSA Vref is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./initiTm2-.sh ${Vreset} ${Vref}"
./send -IP ${ip} -cmd "./initiTm2-.sh ${Vreset} ${Vref}"
