#Tony Liang and hari
#Nov 20 2019
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
import sys
import subprocess
import serial
import RPi.GPIO as GPIO
import time
import os
import signal
filename = "steeringdata.txt"

acmn = sys.argv[1] #port n for arduino usually 1 or 0
usbn = sys.argv[2] #port n for lidar, usually 1 or 0
print("dev/ttyUSB" + usbn)

#usbforlidarprompt = sys.argv[1]#this will be a number, usually 1 or 2
#usbforserialprompt = sys.argv[2]
#usbforlidar = "/dev/ttyUSB" + usbforlidarprompt
#usbforserial = "/dev/ttyACM" + usbforserialprompt
#print("lidar" + usbforlidar + "arduino" + usbforserial)
#cmd.append(usbforlidar)
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple', "/dev/ttyUSB" + usbn]

k = 0
ser=serial.Serial("/dev/ttyACM" + acmn,9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600


def main():
    
    
    
    f = open(filename, "w")

    while True:
        global k
        ser.flushInput()
        read_ser = ser.readline()
        f.write("new data")
        f.write(str(read_ser) + "\n")
        #print(read_ser)
        process = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
        #startTime = time.process_time_ns()
        #while time.process_time_ns() - startTime < .25 * 10^9:
        for line in process.stdout:
            f.write(line)
            k+=1
            if k == 500:
                
                k = 0
                break
       # os.killpg(os.getpgid(cmd.pid), signal.SIGTERM)#end process code from stack overflow
        process.terminate()
    f.close()

if __name__ == "__main__":
    main()
