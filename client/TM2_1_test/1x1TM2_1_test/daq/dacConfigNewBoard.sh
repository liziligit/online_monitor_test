output=dacConfigNewBoard.txt
channel0=$1
channel1=$1
channel2=$1
channel3=$1
channel4=$1
channel5=$1
channel6=$1
channel7=$1
####csa Vreset default 0.78-0.82 #####
####csa ref default 0.62####
csa_ref=$2
echo "config_reg(11,0);">${output}
echo "config_dac_B(0,${channel0});// channel 8  csa Vreset ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel1});// channel 6  csa Vreset ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref});// channel 8   csa ref ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref}); //channel 6  csa ref ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel2});// channel 7  csa Vreset  ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel3}); //channel 5  csa Vreset  ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref});//channel 7 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref}); //channel 5 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo  >>${output}

echo "config_reg(1,0x0000);">>${output}
echo "config_reg(1,0x0001);">>${output}
echo "config_reg(1,0x0000);">>${output}
echo "delay_ms 10">>${output}
echo "config_reg(11,1);">>${output}

echo "config_dac_B(0,${channel4}); //channel 4  csa Vreset  ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel5});   // channel 2  csa Vreset ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref});  //channel 4 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref}); //channel 2 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel6});// channel 3  csa Vreset ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${channel7});//channel 1  csa Vreset ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref});//channel 3 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,${csa_ref});// channel 1 csa ref 0.62 ">>${output}
echo "pulse_reg(4);" >>${output}
echo  >>${output}
echo "config_reg(1,0x0000);">>${output}
echo "config_reg(1,0x0001);">>${output}
echo "config_reg(1,0x0000);">>${output}

echo "delay_ms 10">>${output}

echo "config_reg(11,2);">>${output}
echo  >>${output}
echo  >>${output}
echo "config_dac_B(0,1.3);  //channal 8 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3);  //channal 7 ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3); ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3); ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3); ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3); ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3); ">>${output}
echo "pulse_reg(4);" >>${output}
echo "config_dac_B(0,1.3);  //channal 1 ">>${output}
echo "pulse_reg(4);" >>${output}
echo  >>${output}
echo  >>${output}
echo "config_reg(1,0x0000);" >>${output}
echo "config_reg(1,0x0001);" >>${output}
echo "config_reg(1,0x0000);" >>${output}
echo "delay_ms 10">>${output}
# echo  >>${output}
# echo  >>${output}
