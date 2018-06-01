// sketch08-ultrasonic

// Sensor pin-out:
//  VCC - +5VDC
//  Trig - Transmission 
//  Echo - Response
//  GND - GND

#define SPEED_OF_SOUND_CM_PER_MICROSECOND (0.0343)
#define SPEED_OF_SOUND_INCH_PER_MICROSECOND (0.0135)

int trigPin = 11;
int echoPin = 12;
long duration, cm, inches;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  // In this case, the pulseIn function waits for the echoPin to go HIGH
  // then returns the number of microseconds for the echoPin to go LOW
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance.  
  // The duration is in microseconds.  Since the duration is the time the 
  // pulse takes to go out and then echo back, the duration is divided in half
  long cm = (duration * SPEED_OF_SOUND_CM_PER_MICROSECOND) / 2;
  long inches = (duration * SPEED_OF_SOUND_INCH_PER_MICROSECOND) / 2; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}

