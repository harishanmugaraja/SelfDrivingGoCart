#Tony Liang
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
#cmd = ['/Users/tliang/Desktop/Syslab/rplidar_sdk-master/sdk/output/Darwin/Release/ultra_simple',
       #'/dev/tty.SLAB_USBtoUART', '115200']
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple']
usbforlidarprompt = sys.argv[1]#this will be a number, usually 1 or 2
usbforserialprompt = sys.argv[2]
usbforlidar = "/dev/ttyUSB" + usbforlidarprompt
usbforserial = "/dev/ttyUSB" + usbforserialprompt
cmd.append(usbforlidar)

k = 0
ser=serial.Serial(usbforserial,9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600


def main():
    
    
    
    f = open(filename, "w")

    while True:
        global k
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
        #os.killpg(os.getpgid(cmd.pid), signal.SIGTERM)#end process code from stack overflow
        
    f.close()

if __name__ == "__main__":
    main()
