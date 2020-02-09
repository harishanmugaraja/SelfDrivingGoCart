# Tony Liang and hari Shanmugaraja
# Feb 9 2020
# read in text file for lidar and text file for car motor and steering and match them up
# sample line
# 1581083570.228828 b'8597 1407\r\n'
import sys

import subprocess
import serial
import time
import os
import signal

filename = "steeringdata.txt"
print("cardatafile lidardatafile offset")
threeinputs = input()
splitupinputs = threeinputs.split(" ")
lidarFile = splitupinputs[1]
carFile = "steeringdatacarsample.txt"
offset = float(splitupinputs[2])  # offset accounts for time difference between pi and tony's computer
timeToValues = dict()
timeList = list()

def main():
    global timeList, timeToValues
    with open(carFile) as f:
        for line in f.readlines():
            splitupline = line.split(" ")
            if len(splitupline) == 3:
                time = splitupline[0]
                motor = splitupline[1].lstrip("b'")
                steering = splitupline[2][0:4]
                timeList.append(time)
                valueList = [motor, steering]
                valueTuple = tuple(valueList)
                timeToValues[time] = valueTuple
        f.close()
        timeList = tuple(timeList)
    print(timeList)
    print(timeToValues)


if __name__ == "__main__":
    main()
