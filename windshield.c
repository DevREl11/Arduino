#include <Servo.h>                  // include the Servo library
Servo myServo;                      // create a servo object called myServo
 
// name pins used in the circuit
const int onButtonPin = 3;
const int servoPin = 11;
 
// declare variable
int wiperState = 0;
 
void setup() {
  // declare pins used on Arduino as INPUTS or OUTPUTS
  pinMode(onButtonPin,INPUT);
  myServo.attach(servoPin);
  
  // open a serial connection to the computer
  Serial.begin(9600);
  
  // move the servo to the down position
  myServo.write(0);
}
void loop() {
  // change the wiperState if the button is pressed
  if (digitalRead(onButtonPin) == HIGH) {
    wiperState = wiperState + 1;
    if (wiperState >= 2) {wiperState = 0;}
  }
  
  // print information to the serial monitor
  Serial.println(wiperState);
  delay(250);
}
