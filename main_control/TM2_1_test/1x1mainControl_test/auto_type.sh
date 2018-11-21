#open three windows
gnome-terminal --window --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"'

#open two windows
gnome-terminal --window -e --tab -e 'bash -c "ssh -Y addy1@192.168.3.201;exec bash"' --tab -e 'bash -c "ssh -Y addy2@192.168.3.202;exec bash"'　

#final
#gnome-terminal --window --tab --tab -x bash -c "ssh -Y addy2@192.168.3.202 -t 'cd /home/addy1/1x1TM2_1_test/script_bm; bash --login';exec bash;" &&gnome-terminal --window --tab -x bash -c "ssh -Y addy2@192.168.3.202 -t 'cd /home/addy1/1x1TM2_1_test/script_bm; bash --login';exec bash;"


sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy1/1x1TM2_1_test/listen"
xdotool key Return
:'
sleep 1
xdotool type  "./listen 1 -10 10"
'

xdotool key alt+2
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/listen"
xdotool key Return
:'
sleep 1
xdotool type  "./listen 1 -10 10"
'

xdotool key Alt+Tab
sleep 1
xdotool type  "cd /home/liujun/Desktop/1x1mainControl_test/send"
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
xdotool key Return


xdotool key alt+3
sleep 1
xdotool type  "abc123"
xdotool key Return
sleep 1
xdotool type  "cd /home/addy2/1x1TM2_1_test/script_bm"
xdotool key Return
sleep 1
xdotool type  "./listen"
xdotool key Return
'
