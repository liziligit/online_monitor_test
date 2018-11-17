fileId=$1
lowLimitPixel=$2 # minimum signal value of pixel 
upLimitPixel=$3  # maximum signal value of pixel 
if [ "$1" = "" ]
then
  echo Data number is empty
fi
if [ "$2" = "" ]
then
  echo TH2D Min Range is empty
fi

if [ "$3" = "" ]
then
  echo TH2D Max Range is empty
  exit
fi

set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./pd3SyncDraw2D_send.sh ${Id} ${fileId} ${lowLimitPixel} ${upLimitPixel}
done
