#Tony Liang
#Nov 20 2019
#take in value written to writeMicroseconds() on the arduino and log it in a text file here.
import subprocess
import serial
import RPi.GPIO as GPIO
import time

filename = "steeringdata2.txt"
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple']

ser=serial.Serial("/dev/ttyUSB1",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

def main():
    print("hi")
    f = open(filename, "w")
    while True:
        read_ser = ser.readline()
        f.write("new data")
        f.write(str(read_ser) + "\n")
        #print(read_ser)
        process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
        startTime = time.process_time_ns()
        while time.process_time_ns() - startTime < .2 * 10^9:
            for line in process.stdout:
                f.write(line)
        
    f.close()

if __name__ == "__main__":
    main()
