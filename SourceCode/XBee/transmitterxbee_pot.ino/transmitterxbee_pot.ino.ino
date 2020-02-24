//This is code for the transmitter
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); // RX, TX
int throttlePin = 1;
int steeringPin = 2;
int throttleVal;
int steeringVal;
void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  xbee.begin(9600);
}
void loop() { // run over and over
  throttleVal = analogRead(throttlePin);
  steeringVal = analogRead(steeringPin);
  throttleVal+=1000;
  steeringVal+=1000;//this is the time spent on high, steeringVal must be between 1000 and 2000
  if (throttleVal > 2000)
  {
    throttleVal = 2000;
  }
  if (throttleVal < 1000)
  {
    throttleVal = 1000;
  }
  
  String msg = String(throttleVal);
  String msg2 = String(steeringVal);
  String finalmsg = msg+" "+msg2+"\n";
  xbee.print(finalmsg);
  Serial.print(finalmsg);
  delay(100);
}
