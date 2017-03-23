// nastavi delku cekani
const int cekani = 100;
const int cekanimezi = 50;

// nastavi cisla pinu pro led
const int red1 = 11;
const int red2 = 10;
const int red3 = 9;
const int red4 = 8;

// reknu mu ze na nej budu psat
void setup() {
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(red4, OUTPUT);
}

// udelam blok blikni
void blikni(int led) {
  digitalWrite(led, HIGH);
  delay(cekani);
  digitalWrite(led, LOW);
}

// udelam blok vsechny
void blikniVsechny() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  delay(cekani);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(red4, LOW);
  delay(cekanimezi);
}

void loop() {
  blikni(red1);
  blikni(red2);
  blikni(red3);
  blikni(red4);
  blikni(red3);
  blikni(red2);
  blikni(red1);
  blikniVsechny();
  blikniVsechny();
}
