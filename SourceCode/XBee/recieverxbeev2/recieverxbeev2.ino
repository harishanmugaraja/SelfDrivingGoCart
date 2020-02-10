//This is code for the receiver
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial xbee(10, 11); // RX, TX

void setup() {
// Open serial communications and wait for port to open:
Serial.begin(9600);
xbee.begin(9600);
pinMode(LED_BUILTIN,OUTPUT);
}
void charToString(char S[], String &D)
{
 
 String rc(S);
 D = rc;
 
}
void loop() { // run over and over
  while(xbee.available() > 0){
    char c = xbee.read();    
    Serial.println(c);
  }
}
