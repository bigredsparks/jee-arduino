// sketch07-servo

// Servo wire color code:
//   black - GND
//   red - +5VDC
//   yellow - PWM signal

#include <Servo.h>
Servo servo;  // create servo object to control a servo

int analogInPin = A0; // analog input pin 0
int analogOutPin = 3; // analog output pin 3.  

void setup() {
  // attach the servo on output pin to the servo object
  servo.attach(analogOutPin);  
}

void loop() {
  // read the analog input
  int analogVal = analogRead(analogInPin);

  // map to angle between 0 and 180 degrees
  int servoAngle = map(analogVal, 0, 1023, 0, 180);

  // write angle to servo
  servo.write(servoAngle);

  // wait for servo to get to position
  delay(15);                           
}

