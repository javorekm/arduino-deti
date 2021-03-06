#include "U8glib.h"

// inicializace OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

const uint8_t vesely[] PROGMEM = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x7f,0xff,0x80,0x0,0x0,0x0,
0x0,0x0,0x7,0xff,0xff,0xf8,0x0,0x0,0x0,
0x0,0x0,0x1f,0x80,0x0,0x7e,0x0,0x0,0x0,
0x0,0x0,0x7c,0x0,0x0,0xf,0x80,0x0,0x0,
0x0,0x1,0xe0,0x0,0x0,0x1,0xe0,0x0,0x0,
0x0,0x3,0x80,0x0,0x0,0x0,0x70,0x0,0x0,
0x0,0xf,0x0,0x0,0x0,0x0,0x3c,0x0,0x0,
0x0,0x1c,0x0,0x0,0x0,0x0,0xe,0x0,0x0,
0x0,0x38,0x0,0x0,0x0,0x0,0x7,0x0,0x0,
0x0,0x70,0x0,0x0,0x0,0x0,0x3,0x80,0x0,
0x0,0xe0,0x0,0x0,0x0,0x0,0x1,0xc0,0x0,
0x1,0xc0,0x0,0x0,0x0,0x0,0x0,0xe0,0x0,
0x3,0x80,0x0,0x0,0x0,0x0,0x0,0x70,0x0,
0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,
0x6,0x0,0x7,0x80,0x0,0x3c,0x0,0x18,0x0,
0x6,0x0,0x1f,0xe0,0x0,0xff,0x0,0x18,0x0,
0xc,0x0,0x3f,0xf0,0x1,0xff,0x80,0xc,0x0,
0xc,0x0,0x70,0x38,0x3,0x81,0xc0,0xc,0x0,
0x18,0x0,0xe0,0x1c,0x7,0x0,0xe0,0x6,0x0,
0x18,0x0,0xe0,0x1c,0x7,0x0,0xe0,0x6,0x0,
0x18,0x0,0xe3,0x1c,0x7,0x18,0xe0,0x6,0x0,
0x30,0x0,0xe7,0x9c,0x7,0x3c,0xe0,0x3,0x0,
0x30,0x0,0xe7,0x9c,0x7,0x3c,0xe0,0x3,0x0,
0x30,0x0,0xe7,0x9c,0x7,0x3c,0xe0,0x3,0x0,
0x30,0x0,0xe3,0x1c,0x7,0x18,0xe0,0x3,0x0,
0x30,0x0,0xe0,0x1c,0x7,0x0,0xe0,0x3,0x0,
0x30,0x0,0xe0,0x1c,0x7,0x0,0xe0,0x3,0x0,
0x30,0x0,0x70,0x38,0x3,0x81,0xc0,0x3,0x0,
0x30,0x0,0x3f,0xf0,0x1,0xff,0x80,0x3,0x0,
0x30,0x10,0x1f,0xe0,0x0,0xff,0x0,0x3,0x0,
0x30,0x18,0x7,0x80,0x0,0x3c,0x0,0x3,0x0,
0x30,0x18,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x30,0x1c,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x30,0x1c,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x18,0xe,0x0,0x0,0x0,0x0,0x0,0x6,0x0,
0x18,0xf,0x0,0x0,0x0,0x0,0x0,0x6,0x0,
0x18,0x7,0x80,0x0,0x0,0x0,0x0,0x6,0x0,
0xc,0x3,0xc0,0x0,0x0,0x0,0x70,0xc,0x0,
0xc,0x1,0xe0,0x0,0x0,0x0,0xf0,0xc,0x0,
0x6,0x0,0xf8,0x0,0x0,0x1,0xe0,0x18,0x0,
0x6,0x0,0x7f,0x0,0x0,0x3,0xc0,0x18,0x0,
0x3,0x0,0x1f,0x80,0x0,0x7,0x80,0x30,0x0,
0x3,0x80,0x7,0xe0,0x0,0x1f,0x0,0x70,0x0,
0x1,0xc0,0x1,0xfc,0x0,0xfe,0x0,0xe0,0x0,
0x0,0xe0,0x0,0x7f,0xff,0xf8,0x1,0xc0,0x0,
0x0,0x70,0x0,0x1f,0xff,0xe0,0x3,0x80,0x0,
0x0,0x38,0x0,0x0,0xfe,0x0,0x7,0x0,0x0,
0x0,0x1c,0x0,0x0,0x0,0x0,0xe,0x0,0x0,
0x0,0xf,0x0,0x0,0x0,0x0,0x3c,0x0,0x0,
0x0,0x3,0x80,0x0,0x0,0x0,0x70,0x0,0x0,
0x0,0x1,0xe0,0x0,0x0,0x1,0xe0,0x0,0x0,
0x0,0x0,0x7c,0x0,0x0,0xf,0x80,0x0,0x0,
0x0,0x0,0x1f,0x80,0x0,0x7e,0x0,0x0,0x0,
0x0,0x0,0x7,0xff,0xff,0xf8,0x0,0x0,0x0,
0x0,0x0,0x0,0x7f,0xff,0x80,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

int sirka_displeje = 128;
int vyska_displeje = 64;

int sirka_obrazku = 65;
int vyska_obrazku = 57;

// vycentrovane souradnice pro obrazek
int x = (sirka_displeje - sirka_obrazku) / 2;
int y = (vyska_displeje - vyska_obrazku) / 2;

void setup() {
  // nic
}

// vypise vysledek na displeji
void vykresli() {
  //x = x souradnice, kde zacne kreslit obrazek (0;0 - levy horni roh)
  //y = y souradnice, kde zacne kreslit obrazek (0;0 - levy horni roh)
  //pocet bajtu na sirku obrazku
  //vyska obrazku
  //obrazek
  int pocet_bajtu_sirka_obrazku = (int)(sirka_obrazku / 8.0 + 0.5);
  u8g.drawBitmapP(x, y, pocet_bajtu_sirka_obrazku, vyska_obrazku, vesely);
}

void loop() {
  u8g.firstPage();
  do {
    vykresli();
  } while (u8g.nextPage());

  delay(1000);
}
