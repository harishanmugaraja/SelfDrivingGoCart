//This is code for the receiver
#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
SoftwareSerial xbee(10, 11); // RX, TX
int potPinSteer = 2;    // select the input pin for the potentiometer
int potPinDrive = 1;
int valSteer = 0;       // variable to store the value coming from the sensor
int valDrive = 0;

void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  xbee.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  myservo.attach(3); //arduino to steering
  pinMode(6, OUTPUT); //arduino to engine
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
        String msg = String(a)+String(b)+String(c)+String(d)+String(e)+String(f)+String(g)+String(h)+String(i)+String(j);
        int valDrive = toInt(msg.substring(0,4));
        int valSteer = toInt(msg.substring(5,9));

        myservo.writeMicroseconds(valSteer);

        int wvalDrive = 10000 - valDrive; //10k - (1500-2000) full reverse to full forward is 1000 to 2000
        count = 0;
        while(count<39){//39 milliseconds
        digitalWrite(6, HIGH);
        delayMicroseconds(valDrive);
        digitalWrite(6, LOW);
        delayMicroseconds(wvalDrive);
        count+=1;
        }
      
        Serial.flush();//new line added to clear serial
        Serial.print(wvalDrive);//value written to writems
        Serial.print(" ");
        Serial.println(wvalSteer);
        
        Serial.println();
        
    }
  }
}
