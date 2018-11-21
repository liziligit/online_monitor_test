fileId=$1
pedeId=$2
lowLimitPixel=$3 # minimum signal value of pixel 
upLimitPixel=$4  # maximum signal value of pixel 
store_file_name=$5
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo Pedestal number is empty
fi
if [ "$3" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$4" = "" ]
then
  echo TH2D Max Range is empty
  exit
fi

if [ "$5" = "" ]
then
  echo store_file_name is empty
  exit
fi

set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./pd1SyncDraw2D_send.sh ${Id} ${fileId} ${pedeId} ${lowLimitPixel} ${upLimitPixel} ${store_file_name}
done
