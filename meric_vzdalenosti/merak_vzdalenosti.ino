#include <SPI.h>
#include <Wire.h>
#include "U8glib.h"

// nastaveni pinu
#define trigPin 13
#define echoPin 12

// inicializace OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

void setup() {
  // seriova konzole pro testy
  // Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// vypise vysledek na displeji
void vypis(int vzdalenost) {
  if (vzdalenost > 400) {
    u8g.setFont(u8g_font_fur20);
    u8g.drawStr(10, 40, "Daleko");
  } else {
    u8g.setFont(u8g_font_fub25n);
    char buf[4];
    sprintf(buf, "%03i", vzdalenost);
    u8g.drawStr(40, 30, buf);
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(45, 50, "cm");
  }
}

void loop() {
  long duration, vzdalenost;
  // PULSE ___|---|___
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // precteme echo pin
  duration = pulseIn(echoPin, HIGH);
  //prepocet na vzdalenost
  vzdalenost = (duration / 2) / 29.1;

  u8g.firstPage();
  do {
    vypis(vzdalenost);
  } while (u8g.nextPage());

  // Serial.println(distance);
  delay(500);
}
