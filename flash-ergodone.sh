PORT=/dev/ttyACM0
sudo python ./ergodone-reset.py $PORT
sleep 2
sudo avrdude -patmega32u4 -cavr109 -P$PORT -Uflash:w:./ergodone_my.hex:i
