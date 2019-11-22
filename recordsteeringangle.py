#Tony Liang
#Nov 20 2019
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
filename = "steeringdata.txt"

import serial
import RPi.GPIO as GPIO
import time

ser=serial.Serial("/dev/ttyACM0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def main():
    f = open(filename, "w")
    while True:
        read_ser = ser.readline()
        f.write(str(read_ser) + "\n")
        print(read_ser)
    f.close()

if __name__ == "__main__":
    main()