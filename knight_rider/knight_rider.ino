void setup() {
  // nastaveni pinu pro zapis
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // problikni LED na pinech 2 az 6
  for (int i = 2; i < 7; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);
  }
  // problikni LED na pinech 5 az 3
  for (int i = 5; i > 2; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);
  }
}
