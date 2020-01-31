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

acmn = sys.argv[1] #port n for arduino usually 1 or 0
usbn = sys.argv[2] #port n for lidar, usually 1 or 0
print("dev/ttyUSB" + usbn)
print("dev/ttyACM" + acmn)

cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple', "/dev/ttyUSB" + usbn]

k = 0
ser=serial.Serial("/dev/ttyACM" + acmn,9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def main():
    
    startTime = time.time()
    print(startTime)
    fLidar = open(filenameLidar, "w")
    fCar = open(filenameCar, "w")

    while True:
        global k
        currentSteeringData = readLastLine(ser)
        print(currentSteeringData)
        currentTime = time.time() - startTime
        #fLidar.write("time" + str(currentTime) + "\n")
        fCar.write("time" + str(currentTime) + currentSteeringData + "\n")
        #print(read_ser)
        #process = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
        #for line in process.stdout:
        #    fLidar.write(line)
        #    k+=1
        #    if k == 500:
        #
        #        k = 0
        #        break
        #process.terminate()
    f.close()


def readLastLine(ser):
    last_data=''
    while True:
        data=ser.readline()
        if data!='':
            last_data=data
            print(last_data)#added
        else:
            return last_data#we can put a keyword

if __name__ == "__main__":
    main()
