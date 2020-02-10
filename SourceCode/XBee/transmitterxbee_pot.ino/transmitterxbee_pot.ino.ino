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
}//
void loop() { // run over and over
  throttleVal = analogRead(throttlePin);
  steeringVal = analogRead(steeringPin);
  String msg = String(throttleVal);
  String msg2 = String(steeringVal);
  xbee.print(msg+"\n"+msg2+"\n");
  delay(500);
}
