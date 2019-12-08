int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int buttonPinLeft = 7;     // the number of the pushbutton pin
int buttonPinRight = 8;

int buttonStateLeft = 0;         // variable for reading the pushbutton status
int buttonStateRight = 0;
#include <Servo.h>
Servo myservo;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);
  myservo.attach(3);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  //Serial.println(val);
  int wval = 1000 + val; //written val to servo
  myservo.writeMicroseconds(wval);
  
  buttonStateRight = digitalRead(buttonPinRight);
  buttonStateLeft = digitalRead(buttonPinLeft);

  // quick turns to full left and full right
  if (buttonStateLeft == HIGH) {
    wval = 1000;
    myservo.writeMicroseconds(wval);
    digitalWrite(ledPin, HIGH);
    delay(10);
  } 
  if (buttonStateRight == HIGH) {
    wval = 2000;
    myservo.writeMicroseconds(wval);
    digitalWrite(ledPin, HIGH);
    delay(10);
  }
  digitalWrite(ledPin, LOW);
  Serial.println(wval);//value written to writems
  //Serial.println(myservo.read());//angle
  
}
