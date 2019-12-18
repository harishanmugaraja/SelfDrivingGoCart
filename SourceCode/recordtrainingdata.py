#Tony Liang
#Nov 20 2019
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
import subprocess
import serial
import RPi.GPIO as GPIO
import time
import os
import signal
filename = "steeringdata.txt"
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple']

ser=serial.Serial("/dev/ttyUSB0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def main():
    f = open(filename, "w")

    while True:
        read_ser = ser.readline()
        f.write("new data")
        f.write(str(read_ser) + "\n")
        #print(read_ser)
        process = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
        startTime = time.process_time_ns()
        while time.process_time_ns() - startTime < .25 * 10^9:
            for line in process.stdout:
                f.write(line)
        os.killpg(os.getpgid(cmd.pid), signal.SIGTERM)#end process code from stack overflow
        
    f.close()

if __name__ == "__main__":
    main()
