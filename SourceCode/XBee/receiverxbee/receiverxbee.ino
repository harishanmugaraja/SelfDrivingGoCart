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
  char a, b, c, d; 
  int len = 0;
  a = xbee.read();
  b = xbee.read();
  if(b!=10){
   len+=1;
   c = xbee.read();
    if(c!=10){
      len+=1;
      d = xbee.read();
      if(d!=10){
        len+=1;
      }
    }
  }
  if(len==1){
    String msg;
    char mone[1] = {a};
    charToString(mone,msg);
    Serial.println(msg);
  }
  if(len==2){
    String msg;
    char mone[2] = {a,b};
    charToString(mone,msg);
    Serial.println(msg);
  }
  if(len==3){
    String msg;
    char mone[3] = {a,b,c};
    charToString(mone,msg);
    Serial.println(msg);
  }
  if(len==4){
    String msg;
    char mone[4] = {a,b,c,d};
    charToString(mone,msg);
    Serial.println(msg);
  }
}
}
