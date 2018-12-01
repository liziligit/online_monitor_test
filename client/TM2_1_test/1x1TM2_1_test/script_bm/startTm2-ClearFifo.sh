script_BM=../script_bm
cd ../daq

for((i=1;i<=3;i++))
do
./mytcp -c start.c 192.168.2.3
echo "clear fifo ${i} of 3"
sleep 1
done
cd ${script_BM}
