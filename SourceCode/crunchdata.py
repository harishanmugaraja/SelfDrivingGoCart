# Tony Liang and hari Shanmugaraja
# Feb 9 2020
# read in text file for lidar and text file for car motor and steering and match them up
# sample line
# 1581083570.228828 b'8597 1407\r\n'
#
#
# Ultra simple LIDAR data grabber for RPLIDAR.
# Version: 1.10.0
# 1582122195.06
# RPLIDAR S/N: BE9B9AF2C1EA98D4BEEB9CF031483517
# Firmware Ver: 1.25
# Hardware Rev: 5
# RPLidar health status : 0
#    theta: 0.30 Dist: 00781.00 Q: 47
#    theta: 1.05 Dist: 00780.00 Q: 47
#    theta: 1.55 Dist: 00789.00 Q: 47
#    theta: 2.17 Dist: 00782.00 Q: 47
#    theta: 3.09 Dist: 00000.00 Q: 0
#    theta: 3.55 Dist: 01044.00 Q: 47

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
carFile = splitupinputs[0]#"steeringdatacarsample.txt"

offset = float(splitupinputs[2])  # offset accounts for time difference between pi and tony's computer
timeToValues = dict()#arduino time to steering data
timeList = list()#list of times from arduino

timeListLidar = list()#list of times from pi
timeToLidarPoints = list()#list of times from pi to lidar points

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

        with open(lidarFile) as fl:
            currentPoints = list()
            currentTime = None
            for line in fl.readlines():
                if "theta" in line:
                    strippedLine = line.strip(" ")
                    splitWords = strippedLine.split(" ")
                    theta = splitWords[0]
                    dist = splitWords[2]
                    pointList = [theta, dist]
                    pointTuple = tuple(pointList)
                    currentPoints.append(pointTuple)
                elif len(line.split(" ")) == 1: #this is the line where only time is printed, reset currentpoints and currenttime
                    currentTime = line
                    timeListLidar.append(currentTime)
                    timeToLidarPoints[currentTime] = currentPoints
                    currentPoints = list()
                    currentTime = None








if __name__ == "__main__":
    main()
