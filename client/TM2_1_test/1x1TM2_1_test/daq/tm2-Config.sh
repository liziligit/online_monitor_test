Vreset=$1 # CSA Vrest 0.78
Vref=$2 # CSA Vref 0.62
echo Configure Tm2-
set Id=0
IdStart=1
IdEnd=10
# generate dacConfigNewBoard.txt
echo ./dacConfigNewBoard.sh ${Vreset} ${Vref}
./dacConfigNewBoard.sh ${Vreset} ${Vref}
sleep 1

echo ./mytcp -c dacTest.c 
./mytcp -c dacTest.c 
sleep 1
echo ./mytcp -c tm2-NewBoard.c 
./mytcp -c tm2-NewBoard.c 
sleep 1
echo ./mytcp -c dacNewBoard.c 
for((Id=${IdStart};Id<=${IdEnd};Id++))
do
	./mytcp -c dacNewBoard.c 
	sleep 0.5
done








