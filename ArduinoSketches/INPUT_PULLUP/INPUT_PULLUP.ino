void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // make default HIGH
  pinMode(13, OUTPUT);

}

void loop() {

  int val = digitalRead(2);
  Serial.println(val, DEC);

  if (val == HIGH) digitalWrite(13, LOW);
  else digitalWrite(13, HIGH);

}
