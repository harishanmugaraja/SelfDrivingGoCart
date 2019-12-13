#Tony Liang Dec 13 2019
import subprocess
#print(subprocess.check_output('ls'))
cmd = ['/Users/tliang/Desktop/Syslab/rplidar_sdk-master/sdk/output/Darwin/Release/ultra_simple',
       '/dev/tty.SLAB_USBtoUART', '115200']
process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
for line in process.stdout:
    print(line)
