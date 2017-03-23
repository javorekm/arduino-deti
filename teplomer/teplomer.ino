const int digitPins[4] = {4, 5, 6, 7};
const int clockPin = 10; // 74HC595 Pin 11
const int latchPin = 11; // 74HC595 Pin 12
const int dataPin = 12;  // 74HC595 Pin 14
const int tempPin = A0;  // datovy pin teplomeru
const byte digits[10] =  // cislice zakodovane jako jednotlive LED 7segmentoveho
                         // displeje
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
        // ABCDEFG. (posledni je tecka)
        B11111100, // 0
        B01100000, // 1
        B11011010, // 2
        B11110010, // 3
        B01100110, // 4
        B10110110, // 5
        B10111110, // 6
        B11100000, // 7
        B11111110, // 8
        B11110110  // 9
};

// jen na zkousku, pozdrav
const byte letters[4] = {
    // ABCDEFG.
    B11101110, // A
    B01101110, // H
    B11111100, // O
    B01111000  // J
};

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // pin pro teplotu
  pinMode(tempPin, INPUT);

  // analogReference(INTERNAL);

  // testovaci konzole
  // Serial.begin(9600);

  // zobraz pozdrav
  for (byte i = 0; i < 200; i++) {
    displayLetter(3, 0);
    displayLetter(2, 1);
    displayLetter(1, 2);
    displayLetter(0, 3);
  }
}

// zobrazi pismeno
// digit = pozice na displeji (zleva, od 0)
// letter = poradi pismene v poli letters
void displayLetter(byte digit, byte letter) {
  // pred posouvanim bitu je potreba vypnout displej
  displayOff();
  // zavora dolu
  digitalWrite(latchPin, LOW);
  // napln shit registr daty o pismenu
  // ~ = bitova negace https://www.arduino.cc/en/Reference/BitwiseXorNot
  // protoze je displej se spolecnou anodou, privadime na anodu +5V z pinu, ktery vybira cislici
  // na katodu je pak potreba privest LOW, aby LED svitila, HIGH, aby nesvitila
  // toho docilime tak, ze prevratime 1 z pole letters/digits na 0 a obracene
  shiftOut(dataPin, clockPin, LSBFIRST, ~letters[letter]);
  // zavora nahoru -> odesilame na vystupni piny shift registru
  digitalWrite(latchPin, HIGH);
  // pust HIGH do vybrane cislice displeje
  digitalWrite(digitPins[digit], HIGH);
  // pockame chvilku na POV (persistence of vision)
  delay(3);
}

// zobrazi cislici na vybrane pozici displeje, automaticky osetruje desetinnou
// tecku za druhou cislici
// digit = pozice, na ktere chceme cislici zobrazit
// number = cislice, kterou chceme zobrazit
void displayDigit(byte digit, byte number) {
  // pred posouvanim bitu je potreba vypnout displej
  displayOff();
  // zavora dolu
  digitalWrite(latchPin, LOW);
  // pokud piseme treti cislici (pocitano od 0), tak rozsvitime i desetinnou
  // tecku
  //
  // ~ = bitova negace https://www.arduino.cc/en/Reference/BitwiseXorNot
  // protoze je displej se spolecnou anodou, privadime na anodu +5V z pinu, ktery vybira cislici
  // na katodu je pak potreba privest LOW, aby LED svitila, HIGH, aby nesvitila
  // toho docilime tak, ze prevratime 1 z pole letters/digits na 0 a obracene
  if (digit == 2) {
    // desetina tecka je bitove posledni, provedeme bitovy OR
    shiftOut(dataPin, clockPin, LSBFIRST, ~(digits[number] | B00000001));
  } else {
    // normalni zapis do shift registru
    shiftOut(dataPin, clockPin, LSBFIRST, ~digits[number]);
  }
  // zavora nahoru -> odesilame na vystupni piny shift registru
  digitalWrite(latchPin, HIGH);
  // pust HIGH do vybrane cislice displeje
  digitalWrite(digitPins[digit], HIGH);
  // pockame chvilku na POV (persistence of vision)
  delay(3);
}

// zhasni vsechny LED
void displayOff() {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], LOW);
  }
}

// aktualizuj displej
void updateDisplay(float number) {
  byte digitBuffer[4] = {0};
  // orizni na 2 desetiny
  number = int(number * 100);
  // setiny
  digitBuffer[3] = int(number) / 1000;
  // desetiny
  digitBuffer[2] = (int(number) % 1000) / 100;
  // jednotky
  digitBuffer[1] = (int(number) % 100) / 10;
  // desitky
  digitBuffer[0] = (int(number) % 100) % 10;

  for (byte i = 0; i < 50; i++) {
    for (byte digit = 0; digit < 4; digit++) {
      // zobraz po sobe vsechny cislice hodnoty
      displayDigit(digit, digitBuffer[digit]);
    }
  }
}

void loop() {
  // precti hodnotu teplomeru
  int reading = analogRead(tempPin);
  // prepocitame hodnotu na stupne
  // rozsah hodnot analogoveho vystupu je 0-1024, (0-5V)
  // teplomer vraci 10mV/stupen C
  // 5 V / 1024 = 4,8828 mV
  // teplota = (5 * hodnota * 100) / 1024
  float tempC = (5 * reading * 100.0) / 1024.0;

  // pokud bychom chteli vyssi presnost, muzeme nastavit jine referencni napeti
  // pro analogovy vstup
  // odpoznamkovat v setup() analogReference(INTERNAL);
  // to nastavi misto 5V referencni napeti 1.1V
  // zmenou referencniho napeti na 1.1 se zmeni rozsah LM35 na 0-110 stupnu C
  // tempC = (1.1 * reading * 100.0) / 1024.0;

  //  Serial.print(tempC);
  //  Serial.println(" C");
  for (int i = 0; i < 10; i++) {
    updateDisplay(tempC);
  }
}
