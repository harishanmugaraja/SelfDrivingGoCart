int buttonPinLeft = 7;     // the number of the pushbutton pin
int buttonPinRight = 8;
// variables will change:
int buttonStateLeft = 0;         // variable for reading the pushbutton status
int buttonStateRight = 0;
#include <Servo.h>
Servo myservo;

void setup() {
  // initialize the LED pin as an output:
  pinMode(buttonPinLeft, INPUT);
  pinMode(buttonPinRight, INPUT);
  Serial.begin(9600);
  myservo.attach(3);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateRight = digitalRead(buttonPinLeft);
  buttonStateLeft = digitalRead(buttonPinRight);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateLeft == HIGH) {
    // turn LED on:
    Serial.println("right");
    myservo.writeMicroseconds(1000);
  } 
  else if (buttonStateRight == HIGH) {
    // turn LED off:
    Serial.println("left");
    myservo.writeMicroseconds(2000);
  }
  else {
    Serial.println("center");
    myservo.writeMicroseconds(1500);
  }
  //delay(200);
}

