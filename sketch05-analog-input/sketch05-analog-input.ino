// sketch05-analog-input

int analogPin = A0; // analog input pin 0
int ledOutputPin = 13;

void setup() {
  // initialize serial connection
  Serial.begin(9600);

  // configure LED output pin as output
  pinMode(ledOutputPin, OUTPUT);
}

void loop() {
  // read the analog input
  int analogValue = analogRead(analogPin);

  // print analog value - it will be a value between 0 and 1023
  Serial.println(analogValue);

  // turn LED on
  digitalWrite(ledOutputPin, HIGH);

  // delay based on analog value read
  delay(analogValue);

  // turn LED off
  digitalWrite(ledOutputPin, LOW);

  // delay based on analog value read
  delay(analogValue);
}
