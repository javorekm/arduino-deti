#include <LiquidCrystal.h>

// inicializace LCD
// 1. parametr = pin Arduina, na ktery je pripojen RS pin LCD
// 2. parametr =  pin Arduina, na ktery je pripojen enable pin LCD
// 3. - 6. parametr = piny Arduina, na ktere jsou pripojeny datove piny d4 - d7 z LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // nastartuj LCD(pocet_sloupcu, pocet_radek)
  lcd.begin(16, 2);
  lcd.print("Jsme frajeri!");
}

void loop() {
// zatim nic
}
