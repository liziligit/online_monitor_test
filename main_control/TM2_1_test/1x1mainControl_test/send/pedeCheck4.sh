pedeId=$1
./startTm2-ClearFifo_send.sh
sleep 3
set Id=0
for((Id=1;Id<=4;Id++))
do
	 ./pedeCheck_send.sh ${Id} ${pedeId}
done
