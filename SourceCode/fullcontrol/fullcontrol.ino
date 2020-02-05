int potPinSteer = 2;    // select the input pin for the potentiometer
int potPinDrive = 1;
int ledPin = 13;   // select the pin for the LED
int valSteer = 0;       // variable to store the value coming from the sensor
int valDrive = 0;
int buttonPin = 8;

int buttonState = 0;         // variable for reading the pushbutton status
int ledState = 0;
#include <Servo.h>
Servo myservo;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);
  myservo.attach(3); //arduino to steering
  pinMode(6, OUTPUT); //arduino to engine
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
  
  int wvalDrive = 10000 - valDrive; //10k - (1500-2000) full reverse to full forward is 1000 to 2000
  digitalWrite(6, HIGH);
  delayMicroseconds(valDrive);
  digitalWrite(6, LOW);
  delayMicroseconds(wvalDrive);
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (ledState == 0){
      digitalWrite(ledPin, HIGH);
      ledState = 1;
    }
    else if (ledState == 1){
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
  } 
  Serial.flush();//new line added to clear serial
  Serial.print(wvalDrive);//value written to writems
  Serial.print(" ");
  Serial.print(wvalSteer);
  delay(500);
  //Serial.println(myservo.read());//angle
  
}
