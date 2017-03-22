// jak dlouho ma pockat
const int cas = 100;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // rozsvit
  digitalWrite(9, HIGH);
  digitalWrite(13, HIGH);
  // cekej
  delay(cas);
  // zhasni
  digitalWrite(9, LOW);
  digitalWrite(13, LOW);
  // cekej
  delay(cas);
  // rozsvit
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  // cekej
  delay(cas);
  // zhasni
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  // cekej
  delay(cas);
}
