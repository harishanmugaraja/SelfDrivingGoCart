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

  while(xbee.available()>0){
    delay(100);
    char a,b,c,d,e,f,g,h,i,j;
    int msg_length = xbee.available();
    String msg;
    if(msg_length==2){
        a=xbee.read();
        b=xbee.read();
        Serial.println(String(a)+String(b));
    }
    if(msg_length==3){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        Serial.println(String(a)+String(b)+String(c));
    }
    if(msg_length==4){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d));
    }
    if(msg_length==6){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        e=xbee.read();
        f=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d)+String(e)+String(f));
    }
    if(msg_length==7){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        e=xbee.read();
        f=xbee.read();
        g=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d)+String(e)+String(f)+String(g));
    }
    if(msg_length==8){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        e=xbee.read();
        f=xbee.read();
        g=xbee.read();
        h=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d)+String(e)+String(f)+String(g)+String(h));
    }
    if(msg_length==9){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        e=xbee.read();
        f=xbee.read();
        g=xbee.read();
        h=xbee.read();
        i=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d)+String(e)+String(f)+String(g)+String(h)+String(i));
    }
    if(msg_length==10){
        a=xbee.read();
        b=xbee.read();
        c=xbee.read();
        d=xbee.read();
        e=xbee.read();
        f=xbee.read();
        g=xbee.read();
        h=xbee.read();
        i=xbee.read();
        j=xbee.read();
        Serial.println(String(a)+String(b)+String(c)+String(d)+String(e)+String(f)+String(g)+String(h)+String(i)+String(j));
    }
  }
}
