#include "U8glib.h"

// inicializace OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
// nastaveni pinu joysticku
const int vy_pin = A0;
const int vx_pin = A1;
const int switch_pin = 7;

const int sirka_displeje = 128;
const int vyska_displeje = 64;

const int mala_rychlost = 1;
const int velka_rychlost = 5;

// zobrazuje se pozdrav?
int pozdrav = 0;

// aktualni souradnice puntiku
int x = 0;
int y = 0;
// nove souradnice punitku
int nx = 0;
int ny = 0;

void setup() {
  //  Serial.begin(9600);
  pinMode(vx_pin, INPUT);
  pinMode(vy_pin, INPUT);
  pinMode(switch_pin, INPUT);
  // zatim nevim proc
  digitalWrite(switch_pin, HIGH);
}

void vykresli(int x, int y) {
  u8g.setColorIndex(1);
  u8g.drawPixel(x, y);
}

void smaz(int x, int y) {
  u8g.setColorIndex(0);
  u8g.drawPixel(x, y);
}

int dejRychlost(int joystick) {
  if (joystick > 850) {
    return velka_rychlost;
  } else if (joystick > 650) {
    return mala_rychlost;
  } else if (joystick < 150) {
    return -velka_rychlost;
  } else if (joystick < 350) {
    return -mala_rychlost;
  }
  return 0;
}

void loop() {
  // precti stav joysticku
  int vx = analogRead(vx_pin);
  int vy = analogRead(vy_pin);
  int sw = digitalRead(switch_pin);
  //  Serial.println(sw);

  // detekce, zda je stisknuty spinac, stisknuto = LOW
  if (sw == LOW) {
    if (pozdrav == 0) {
      pozdrav = 1;
    } else {
      pozdrav = 0;
    }
  }

  // zobraz pozdrav
  if (pozdrav == 1) {
    u8g.setFont(u8g_font_osb18);
    // vykresli napis
    u8g.firstPage();
    do {
      u8g.drawStr(20, 25, "A H O J");
      u8g.drawStr(55, 55, ":-)");
    } while (u8g.nextPage());
  } else {
    // spocitej posun
    nx = x + dejRychlost(vx);
    ny = y + dejRychlost(vy);
    // ohraniceni displejem, kontrola rozsahu, aby to nepodlezlo
    if (nx < 0) {
      nx = 0;
    }
    if (ny < 0) {
      ny = 0;
    }
    if (nx >= sirka_displeje) {
      nx = sirka_displeje - 1;
    }
    if (ny >= vyska_displeje) {
      ny = vyska_displeje - 1;
    }
    // pokud se nekam pohnul, tak smaz stary bodik
    if ((nx != x) || (ny != y)) {
      smaz(x, y);
    }
    // vykresli novy
    u8g.firstPage();
    do {
      vykresli(nx, ny);
    } while (u8g.nextPage());
    x = nx;
    y = ny;
  }
  delay(5);
}
