ip=$1
fileId=$2
lowLimitPixel=$3 # minimum signal value of pixel 
upLimitPixel=$4  # maximum signal value of pixel 


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
  echo TH2D Min Range is empty
fi

if [ "$4" = "" ]
then
  echo TH2D Max Range is empty
  exit
fi

echo ./send -IP ${ip} -cmd "./pd3SyncDraw2D.sh ${fileId} ${lowLimitPixel} ${upLimitPixel} ${ip}"
./send -IP ${ip} -cmd "./pd3SyncDraw2D.sh ${fileId} ${lowLimitPixel} ${upLimitPixel} ${ip}"
