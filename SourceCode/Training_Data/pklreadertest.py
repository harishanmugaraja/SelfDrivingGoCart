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


#output: big list: inside list: 360 (theta, dist) tuples followed by motor, steering
import sys
import random
import subprocess
#import serial
import time
import os
import signal
import pickle



def main():
    with open("pkl39.pkl", "rb") as infile:
        inputandoutput = pickle.load(infile)
        outputonly = pickle.load(infile)

    for i in inputandoutput:
        print(i)

    for o in outputonly:
        print(o)





if __name__ == "__main__":
    main()
