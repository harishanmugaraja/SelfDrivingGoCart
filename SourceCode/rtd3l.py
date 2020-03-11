#Tony Liang and hari
#Jan 31 2020
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
#python 3
import sys
import subprocess
import serial
#import RPi.GPIO as GPIO
import time
import os
#import keyboard
import signal
filenameLidar = "steeringdatalidar3.txt"
filenameCar = "steeringdatacar.txt"

usbn = sys.argv[1] #port n for lidar, usually 1 or 0
timeToRun = sys.argv[2]#time in seconds
print("dev/ttyUSB" + usbn)
startTime = time.time()
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple', "/dev/ttyUSB" + usbn]


def main():
    fLidar = open(filenameLidar, "w")

    
    global k
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
    for line in process.stdout:
        if "S" in line:
            fLidar.write(str(time.time()) + "\n")
        fLidar.write(line)
        if time.time() - startTime > timeToRun:
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
