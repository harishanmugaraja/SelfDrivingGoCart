//This is code for the transmitter
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); // RX, TX
String msg = "Hello this is Tony talking to Hari! ";
int msglen = msg.length();
int count = 0;
void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  xbee.begin(9600);
}//
void loop() { // run over and over
  /*xbee.write('w');
  delay(1000);*/
  xbee.write(msg[count%msglen]);
  count+=1;
  delay(500);
}
