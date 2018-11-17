Vreset=$1
Vref=$2
if [ "$1" = "" ]
then
  echo CSA Vreset is empty
fi
if [ "$2" = "" ]
then
  echo CSA Vref is empty
  exit
fi
./configTm2-.sh ${Vreset} ${Vref}

