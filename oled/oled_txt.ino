#include "U8glib.h"

// inicializace OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

void setup() {
  // nic
}

// vypise vysledek na displeji
void vypis() {
    u8g.setFont(u8g_font_fub25n);
    u8g.drawStr(40, 30, "BAF!");
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(45, 50, "strasidlo");
}

void loop() {
  u8g.firstPage();
  do {
    vypis();
  } while (u8g.nextPage());

  delay(1000);
}
