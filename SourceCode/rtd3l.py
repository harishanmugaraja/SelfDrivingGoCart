#Tony Liang and hari
#Jan 31 2020
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
import sys
import subprocess
import serial
import RPi.GPIO as GPIO
import time
import os
import signal
filenameLidar = "steeringdatalidar.txt"
filenameCar = "steeringdatacar.txt"

usbn = sys.argv[1] #port n for lidar, usually 1 or 0
print("dev/ttyUSB" + usbn)

cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple', "/dev/ttyUSB" + usbn]


def main():
    fLidar = open(filenameLidar, "w")

    
    global k
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
    for line in process.stdout:
        if "S" in line:
            fLidar.write(str(time.time()))
        fLidar.write(line)
    process.terminate()
    fLidar.close()


def readLastLine(ser):
    last_data=''
    while True:
        data=ser.readline()
        if data!='':
            last_data=data
        else:
            return last_data#we can put a keyword

if __name__ == "__main__":
    main()
