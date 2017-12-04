byte pins[6] = {A0, A1, A2, A3, A4, A5};

void setup() {
  // nastartuj seriovo ulinku
  Serial.begin(9600);
  // budeme cist z analogovych pinu
  for (byte i = 0; i < 6; i++) {
    pinMode(pins[i], INPUT);
  }
}

// osetri uzavrenou smycku
void handle(byte pin, char* command) {
  // posli prikaz na seriovou linku
  Serial.print(command);
  int value = 0;
  // dokud se smycka nerozpoji, tak cekej
  while (value < 900) {
    value = analogRead(pins[pin]);
    delay(10);
  }
}

void loop() {
   for (byte i = 0; i < 6; i++) {
    int value = analogRead(pins[i]);
    // pokud je smycka uzavrena
    if (value < 900) {
      //Serial.print(value);
      //Serial.print("\n");
      switch (i) {
        case 0: handle(i, "KEY_SPACE\n"); break;
        case 1: handle(i, "KEY_LEFT\n"); break;
        case 2: handle(i, "KEY_RIGHT\n"); break;
        case 3: handle(i, "KEY_UP\n"); break;
        case 4: handle(i, "KEY_DOWN\n"); break;
        case 5: handle(i, "KEY_ENTER\n"); break;
      }
    }
   }
   delay(10);
}
