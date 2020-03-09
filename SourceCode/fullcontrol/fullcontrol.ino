int potPinSteer = 2;    // select the input pin for the potentiometer
int potPinDrive = 1;
int valSteer = 0;       // variable to store the value coming from the sensor
int valDrive = 0;

#include <Servo.h>
Servo myservo;
Servo esc;
void setup() {
  Serial.begin(9600);
  myservo.attach(3); //arduino to steering
  //pinMode(6, OUTPUT); //arduino to engine
  esc.attach(6);
}

void loop() {
  valSteer = analogRead(potPinSteer);    // read the value from the sensor
  valDrive = analogRead(potPinDrive);
  //Serial.println(val);
  valDrive = 1000 + valDrive;
  
  int wvalSteer = 1000 + valSteer; //written val to servo
  myservo.writeMicroseconds(wvalSteer);

  if (valDrive > 2000)
  {
    valDrive = 2000;
  }
  if (valDrive < 1000)
  {
    valDrive = 1000;
  }
  esc.writeMicroseconds(valDrive);
  int wvalDrive = 10000 - valDrive; //10k - (1500-2000) full reverse to full forward is 1000 to 2000
  /*digitalWrite(6, HIGH);
  delayMicroseconds(valDrive);
  digitalWrite(6, LOW);
  delayMicroseconds(wvalDrive);*/
  

  Serial.flush();//new line added to clear serial
  Serial.print(valDrive);//value written to writems
  Serial.print(" ");
  Serial.println(wvalSteer);
  delay(50);
  //Serial.println(myservo.read());//angle
  
}
