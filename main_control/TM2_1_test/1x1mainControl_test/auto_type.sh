#open five windows
gnome-terminal --window --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"' --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"'
#open four windows
gnome-terminal --window -e --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"' --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"'
#./startTm2-ClearFifo.sh
#./runData.sh 1 6 s test
#./pd1SyncDraw2D.sh 1 1 -10 10 1 test
#./pd1SyncDraw2D.sh 1 1 -10 10 2 test


sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy1/1x1TM2_1_test/script_bm"
xdotool key Return

xdotool key alt+2
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/script_bm"
xdotool key Return

xdotool key alt+3
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy1/1x1TM2_1_test/script_bm"
xdotool key Return

xdotool key alt+4
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/script_bm"
xdotool key Return

xdotool key Alt+Tab
sleep 1
xdotool type  "cd send"
xdotool key Return
xdotool type  "python gui.py"

xdotool key alt+2
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy1/1x1TM2_1_test/script_bm"
xdotool key Return
sleep 1
xdotool type  "./listen"

xdotool key alt+3
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/script_bm"
xdotool key Return
sleep 1
xdotool type  "./listen"

xdotool key alt+4
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy1/1x1TM2_1_test/listen"
xdotool key Return
sleep 1
sleep 1
xdotool type  "./listen 1 -10 10"

xdotool key alt+5
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/listen"
xdotool key Return
sleep 1
sleep 1
xdotool type  "./listen 2 -10 10"