#include <Servo.h>
int p = 3; // potentiometer wiper (middle terminal) connected to analog pin 3
int analogPin = A0;              // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);           //  setup serial
  //myservo.attach(9);
}

void loop() {
  //delay(1);
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val/4);          // Values go from 140 to 255 where 140 is to the right.
  //analogWrite(A1, analogRead(analogPin)/4);
  for (int x = 50; x < 256; x++)
    {
      analogWrite(p, x);
      Serial.println(x);
      delay(200); 
    }
    
}
