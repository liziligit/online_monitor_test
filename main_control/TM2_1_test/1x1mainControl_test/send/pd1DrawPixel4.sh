fileId=$1
ich=$2
ipixel=$3
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Chip ID is empty
fi
if [ "$3" = "" ]
then
  echo Pixel ID is empty
  exit
fi




set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./pd1DrawPixel_send.sh ${Id} ${fileId} ${ich} ${ipixel}
done
