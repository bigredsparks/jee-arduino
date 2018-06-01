// sketch03-switch-debounce-1

// define input and output pins here.  this way they can easily be changed
// without having to modify them everywhere throughout the code
int switchInputPin = 2;
int ledOutputPin = 13;

int switchState = 0; // keeps track of current switch state
int threshold = 50; // threshold (in msecs) to wait for switch to debounce

void setup() {
  // initialize serial connection
  Serial.begin(9600);

  // configure switch input pin as input
  pinMode(switchInputPin, INPUT);

  // configure LED output pin as output
  pinMode(ledOutputPin, OUTPUT);
}

void loop() {
  // read current switch state
  int switchRead = digitalRead(switchInputPin);

  // did switch state change from previous state?
  if (switchRead != switchState) {
    // yes, sleep for threshold msecs
    delay(threshold);

    // is switch state still the same?
    if (switchRead == digitalRead(switchInputPin)) {
      // yes, set current switch state to value read
      switchState = switchRead;
      
      // yes, set led output pin to match switch state
      digitalWrite(ledOutputPin, switchState);

      // send switch state to terminal
      Serial.println(switchState);
    }
  }
}
