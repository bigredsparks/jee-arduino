// sketch06-analog-input-output

int analogInPin = A0; // analog input pin 0
int analogOutPin = 3; // analog output pin 3.  
// Note digital pins 3, 5, 6, 9, 10 and 11 can all be used for PWM output using analogWrite()

void setup() {
  // initialize serial connection
  Serial.begin(9600);
}

void loop() {
  // read the analog input
  int analogValue = analogRead(analogInPin);
  int outputValue = map(analogValue, 0, 1023, 0, 255);

  // print analog value and mapped output value
  Serial.print(analogValue);
  Serial.print(",");
  Serial.println(outputValue);

  // write to output pin
  analogWrite(analogOutPin, outputValue);

  // wait for analog-to-digital converter to settle
  delay(2);
}
