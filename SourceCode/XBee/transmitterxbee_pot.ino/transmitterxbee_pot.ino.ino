//This is code for the transmitter
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); // RX, TX
int potPin = 2;
int val = 0;
void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  xbee.begin(9600);
}//
void loop() { // run over and over
  val = analogRead(potPin);
  String msg = String(val);
  xbee.print(msg);
  xbee.write(10);
  delay(500);
}
