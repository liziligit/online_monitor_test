Vreset=$1
Vref=$2
set Id=0
#for((Id=1;Id<=4;Id++))
for((Id=1;Id<=2;Id++))
do
	./initiTm2-_send.sh ${Id} ${Vreset} ${Vref}
done
