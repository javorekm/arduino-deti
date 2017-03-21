// jak dlouho ma pockat
int sekunda = 1000;

int casC = 15 * sekunda;
int casOC = 1 * sekunda;
int casO = 2 * sekunda;
int casZ = 12 * sekunda;
int casBlik = 300;
int casCHC = 3 * sekunda;
int pinC = 10;
int pinZ = 8;
int pinO = 9;
int pinCHZ = 12;
int pinCHC = 11;

void setup() {
  pinMode(pinZ, OUTPUT); // zelena
  pinMode(pinO, OUTPUT); // oranzova
  pinMode(pinC, OUTPUT); // cervena
  pinMode(pinCHC, OUTPUT); // chodec cervena
  pinMode(pinCHZ, OUTPUT); // chodec zelena
}

void loop() {
  // rozsvit c ch z
  digitalWrite(pinC, HIGH);
  digitalWrite(pinCHZ, HIGH);
  // cekej
  delay(casC);
  // rozsvit z blik
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinCHZ, HIGH);
    delay(casBlik);
    digitalWrite(pinCHZ, LOW);
    delay(casBlik);
  } // rozsvit ch c
  digitalWrite(pinCHC, HIGH);
  digitalWrite(pinC, HIGH);
  delay(casCHC);

  digitalWrite(pinO, HIGH);
  // cekej
  delay(casOC);
  // zhasni c o
  digitalWrite(pinC, LOW);
  digitalWrite(pinO, LOW);
  // rozsvit z
  digitalWrite(pinZ, HIGH);
  // cekej
  delay(casZ);
  // zhasni z
  digitalWrite(pinZ, LOW);
  // rosvit o
  digitalWrite(pinO, HIGH);
  delay(casO);
  digitalWrite(pinO, LOW);
  // blikani
  delay(casBlik);
  for (int i = 0; i < 5; i++) {
    digitalWrite(pinO, HIGH);
    delay(casBlik);
    digitalWrite(pinO, LOW);
    delay(casBlik);
  }
  digitalWrite(pinCHC, HIGH);
  digitalWrite(pinC, HIGH);
  delay(casCHC);
  digitalWrite(pinCHC, LOW);
}
