#Tony Liang and hari
#Feb 5
#take in value written to writeMicroseconds() on the arduino and log it in a text file here. To run on tony's mac
#python 3
import sys
import subprocess
import serial
#import RPi.GPIO as GPIO
import time
import os
import signal
filenameLidar = "steeringdatalidar.txt"
filenameCar = "steeringdatacar3.txt"

k = 0
ser=serial.Serial("/dev/tty.usbserial-AI0518NW",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def main():
    fCar = open(filenameCar, "w")
    
    while True:
        global k
        currentSteeringData = str(ser.readline())
        
        #print(currentSteeringData)
        currentTime = time.time()
        toWrite = str(time.time()) +" " + currentSteeringData + "\n"
        print(toWrite)
        fCar.write(toWrite)
        #print(read_ser)
        
    f.close()


def readLastLine(ser):#not used
    last_data=''
    while True:
        data=ser.readline()
        if data!='':
            last_data=data
        else:
            return last_data#we can put a keyword

if __name__ == "__main__":
    main()
