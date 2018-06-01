// sketch01-digital-input1

// keep track of switch state
int switchState = 0;

void setup() {
  // initialize serial connection
  Serial.begin(9600);

  // configure pin 2 as input
  pinMode(2, INPUT);

  // configure pin 13 as output
  pinMode(13, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);
  Serial.println(switchState);
   
  if (switchState == LOW) {
    // switch is not pressed
    digitalWrite(13, LOW);
  }
  else { // switch == HIGH
    // switch is pressed
    digitalWrite(13, HIGH);
  }
}
