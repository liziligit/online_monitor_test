polNId=$1
./startTm2-ClearFifo_send.sh
sleep 3
set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	 ./tau_send.sh ${Id} ${polNId}
done
