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
  myservo.writeMicroseconds(1000 + val);
  
  buttonStateRight = digitalRead(buttonPinRight);
  buttonStateLeft = digitalRead(buttonPinLeft);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateLeft == HIGH) {
    // turn LED on:
    
    myservo.writeMicroseconds(1000);
    digitalWrite(ledPin, HIGH);
    delay(10);
  } 
  if (buttonStateRight == HIGH) {
    // turn LED off:
    myservo.writeMicroseconds(2000);
    digitalWrite(ledPin, HIGH);
    delay(10);
  }
  digitalWrite(ledPin, LOW);
  Serial.println(myservo.read());//prints angle of wheels
}
