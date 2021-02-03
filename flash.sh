sleep 5
sudo dfu-programmer atmega32u4 erase && sudo dfu-programmer atmega32u4 flash ./bm40hsrgb_my.hex && sudo dfu-programmer atmega32u4 reset
