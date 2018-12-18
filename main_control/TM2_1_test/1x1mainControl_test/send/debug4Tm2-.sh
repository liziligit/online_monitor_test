./startTm2-ClearFifo_send.sh
sleep 5

set Id=0
for((Id=1;Id<=2;Id++))
do
	./debugTm2-_send.sh ${Id} 
done
