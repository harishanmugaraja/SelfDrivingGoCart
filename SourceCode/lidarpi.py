import subprocess
cmd = ['/home/pi/Desktop/rplidar_sdk-master/sdk/output/Linux/Release/ultra_simple',"/dev/ttyUSB0"]
process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
for line in process.stdout:
   print(line)
