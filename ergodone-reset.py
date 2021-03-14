import serial, sys
serialPort = sys.argv[1]
ser = serial.Serial(
        port=serialPort,
        baudrate=1200,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS
)
ser.isOpen()
