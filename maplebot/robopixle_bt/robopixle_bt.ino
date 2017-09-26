#include <SoftwareSerial.h>

// piny pro software serial
const int rxpin = 2;
const int txpin = 3;
// inicializace software serial
SoftwareSerial bluetooth(rxpin, txpin);
char ch = 'A';

// pripojeni pinu motoru
// motor A
const int enA = 6;
const int in1 = 5;
const int in2 = 4;
// motor B
const int enB = 9;
const int in3 = 7;
const int in4 = 8;

// maximalne 255
const int rychlost = 100;
const int rychlostOtocka = 90;
const int delkaOtocka = 280;
const int delkaKrok = 1000;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //inicializace konzole
  Serial.begin(9600);
  Serial.println("Serial ready");

  // inicializace bluetooth
  bluetooth.begin(9600);
  bluetooth.println("Bluetooth ready");
}

// pusti oba motory
// vpred = true, pokud ma jet vpred
// cas = pocet ms, jak dlouho pojede
void obaMotory(bool vpred, int cas) {
  if (vpred) {
    // motor A
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // motor B
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {
    // motor A
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // motor B
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // motor A
  if (vpred) {
    // drobna korekce nerovnomerneho navrtani motoru v pixli
    analogWrite(enA, rychlost + 10);
  } else  {
    analogWrite(enA, rychlost);
  }
  // motor B
  analogWrite(enB, rychlost);  
  delay(cas);
  zastavOba();
}

// pokus o otocku vlevo o 90 stupnu
void zahniVlevo() {
    // motor A
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // motor B
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  // motor A
  analogWrite(enA, rychlostOtocka);
  // motor B
  analogWrite(enB, rychlostOtocka);  
  delay(delkaOtocka + 30);
  zastavOba();
}

// pokus o otocku vpravo o 90 stupnu
void zahniVpravo() {
    // motor A
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // motor B
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  // motor A
  analogWrite(enA, rychlostOtocka);
  // motor B
  analogWrite(enB, rychlostOtocka);  
  delay(delkaOtocka + 30);
  zastavOba();
}

// zastaveni obou motoru
void zastavOba() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  if(bluetooth.available()){
    // nacti znak z bluetooth
    ch = bluetooth.read();
    // vypis na konzoli
    Serial.println(ch);

    if (ch == 'F') {
      Serial.println("Forward");
      obaMotory(true, delkaKrok);
    } else if (ch == 'B') {
      Serial.println("Backward");
      obaMotory(false, delkaKrok);
    } else if (ch == 'R') {
      Serial.println("Right");
      zahniVpravo();
    } else if (ch == 'L') {
      Serial.println("Left");
      zahniVlevo();
    }
  }
  delay(10);
}

