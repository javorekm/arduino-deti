const int digitPins[4] = {4, 5, 6, 7};
const int clockPin = 10; // 74HC595 Pin 11
const int latchPin = 11; // 74HC595 Pin 12
const int dataPin = 12; // 74HC595 Pin 14
const int tempPin = A0; // temperature sensor pin
const byte digits[10] = // seven segment digits in bits
    {
        /*
               A
              +--+
           F  |G | B
              +--+
           E  |  | C
              +--+
               D
        */
        // ABCDEFG.
        B11111100, // 0
        B01100000, // 1
        B11011010, // 2
        B11110010, // 3
        B01100110, // 4
        B10110110, // 5
        B10111110, // 6
        B11100000, // 7
        B11111110, // 8
        B11110110 // 9
};

const byte letters[4] = {
    // ABCDEFG.
    B11101110, // A
    B01101110, // H
    B11111100, // O
    B01111000 // J
};

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // temperature
  pinMode(tempPin, INPUT);
  //  analogReference(INTERNAL);
  //  Serial.begin(9600);

  for (byte i = 0; i < 200; i++) {
    displayLetter(3, 0);
    displayLetter(2, 1);
    displayLetter(1, 2);
    displayLetter(0, 3);
  }
}

void displayLetter(byte digit, byte letter) {
  // Turn off the shift register pins
  // while you're shifting bits:
  displayOff();
  digitalWrite(latchPin, LOW);
  // shift the bits out:
  shiftOut(dataPin, clockPin, LSBFIRST, ~letters[letter]);
  // Set latch high to set segments.
  digitalWrite(latchPin, HIGH);
  digitalWrite(digitPins[digit], HIGH);
  // Wait a bit for POV
  delay(3);
}

void displayDigit(byte digit, byte number) {
  // Turn off the shift register pins
  // while you're shifting bits:
  displayOff();
  digitalWrite(latchPin, LOW);
  // shift the bits out:
  if (digit == 2) {
    // print the decimal point on the 3rd digit
    shiftOut(dataPin, clockPin, LSBFIRST, ~(digits[number] | B00000001));
  } else {
    shiftOut(dataPin, clockPin, LSBFIRST, ~digits[number]);
  }
  // Set latch high to set segments.
  digitalWrite(latchPin, HIGH);
  digitalWrite(digitPins[digit], HIGH);
  // Wait a bit for POV
  delay(3);
}

void displayOff() {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], LOW);
  }
}

void updateDisplay(float number) {
  byte digitBuffer[4] = {0};
  number = int(number * 100);
  digitBuffer[3] = int(number) / 1000;
  digitBuffer[2] = (int(number) % 1000) / 100;
  digitBuffer[1] = (int(number) % 100) / 10;
  digitBuffer[0] = (int(number) % 100) % 10;

  for (byte i = 0; i < 50; i++) {
    for (byte digit = 0; digit < 4; digit++) {
      displayDigit(digit, digitBuffer[digit]);
    }
  }
}

void loop() {
  int reading = analogRead(tempPin);
  // float tempC = reading / 9.31;
  //  float tempC = reading * 0.48828125;
  // convert the analog data to temperature
  float tempC = (5 * reading * 100.0) / 1024.0;
  //  Serial.print(tempC);
  //  Serial.println(" C");
  for (int i = 0; i < 10; i++) {
    updateDisplay(tempC);
  }
}
