// sketch04-switch-debounce-2

// define input and output pins here.  this way they can easily be changed
// without having to modify them everywhere throughout the code
int switchInputPin = 2;
int ledOutputPin = 13;

int switchState = 0; // keeps track of current switch state
int prevSwitchRead = 0; // saves the previous switch read
int threshold = 50; // threshold (in msecs) to wait for switch to debounce
long lastDebounceTime = 0; // timestamp for when the switch read changed - NOTE this has to be a long integer otherwise the value will wrap.

void setup() {
  // initialize serial connection
  Serial.begin(9600);

  // configure switch input pin as input
  pinMode(switchInputPin, INPUT);

  // configure LED output pin as output
  pinMode(ledOutputPin, OUTPUT);

  // set initial LED output state
  digitalWrite(ledOutputPin, switchState);
}

void loop() {
  // read current switch state
  int switchRead = digitalRead(switchInputPin);

  // is read different from previous switch read?
  if (switchRead != prevSwitchRead) {
    // yes, get current timestamp
    lastDebounceTime = millis();
  }

//  Serial.print(switchRead);
//  Serial.print(",");
//  Serial.print(switchState);
//  Serial.print(",");
//  Serial.print(millis());
//  Serial.print(",");
//  Serial.print(lastDebounceTime);
//  Serial.print(",");
//  Serial.println(millis()-lastDebounceTime);

  // has enough time past to check state again?
  if ((millis() - lastDebounceTime) > threshold) {
    
    // yes, is read difference from current switch state?
    if (switchRead != switchState) {
      // yes, set current switch state to value read
      switchState = switchRead;
      
      // yes, set led output pin to match switch state
      digitalWrite(ledOutputPin, switchState);

      // send switch state to terminal
      Serial.println(switchState);
    }
  }
  // save previous switch read
  prevSwitchRead = switchRead;

  // do something else...
}
