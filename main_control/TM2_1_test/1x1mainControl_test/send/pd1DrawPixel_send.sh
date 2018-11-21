ip=$1
fileId=$2
ich=$3
ipixel=$4
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
  echo Chip ID is empty
fi
if [ "$4" = "" ]
then
  echo Pixel ID is empty
  exit
fi


echo ./send -IP ${ip} -cmd "./pd1DrawPixel.sh ${fileId} ${ich} ${ipixel}"
./send -IP ${ip} -cmd "./pd1DrawPixel.sh ${fileId} ${ich} ${ipixel}"
