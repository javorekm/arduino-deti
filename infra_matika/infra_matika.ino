#include <LiquidCrystal.h>
#include <IRremote.h>

// inicializace LCD
// 1. parametr = pin Arduina, na ktery je pripojen RS pin LCD
// 2. parametr =  pin Arduina, na ktery je pripojen enable pin LCD
// 3. - 6. parametr = piny Arduina, na ktere jsou pripojeny datove piny d4 - d7 z LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// pin, na kterem prijimame infra signal
const int RECV_PIN = 13;
// pin pro cervenou LED
const int LED_CHYBA = 9;
// pin pro zelenou LED
const int LED_OK = 10;

// pocitadlo bodu
int body = 0;

// inicializace infracervene knihovny
IRrecv irrecv(RECV_PIN);
decode_results results;

// do kolika vymysli priklady
int max = 0;

void setup() {
  // testovaci konzole
  // Serial.begin(9600);
  randomSeed(analogRead(0));
  irrecv.enableIRIn(); // nastartuj IR prijimac
  // nastartovani LCD displeje, pocet radek, pocet sloupcu
  lcd.begin(16, 2);

  // zeptame se, do kolika budeme generovat priklady
  lcd.print("Do kolika?");
  max = ctiDalkac(0, 1);
  lcd.clear();

  // pokud je to vice nez, tak to zarizneme
  if (max > 100) {
    lcd.print("To je moc,");
    lcd.setCursor(0, 1);
    lcd.print("jedeme do 100");
    max = 100;
    delay(3000);
    lcd.clear();
  }

 //text pro pocitani
  lcd.print("Vypocitej");
}

// precte hodnotu z dalkoveho ovladace Aiwa
// x = pozice x na displeji
// y = pozice y na displeji
// vraci cislo, ktere nacetl, ocekava na konci enter, podporuje backspace pro mazani znaku
int ctiDalkac(int x, int y) {
  bool enter = false;
  int vysledek = 0;
  int cisloDalkac = 0;
  int cislic = 0;
  lcd.setCursor(x, y);
  do {
    bool backspace = false;
    if (irrecv.decode(&results)) {
      switch (results.value) {
      case 0x76044FD4:
        cisloDalkac = 0;
        break;
      case 0x76044FE0:
        cisloDalkac = 1;
        break;
      case 0x76044FD0:
        cisloDalkac = 2;
        break;
      case 0x76044FF0:
        cisloDalkac = 3;
        break;
      case 0x76044FC8:
        cisloDalkac = 4;
        break;
      case 0x76044FE8:
        cisloDalkac = 5;
        break;
      case 0x76044FD8:
        cisloDalkac = 6;
        break;
      case 0x76044FF8:
        cisloDalkac = 7;
        break;
      case 0x76044FC4:
        cisloDalkac = 8;
        break;
      case 0x76044FE4:
        cisloDalkac = 9;
        break;
      case 0x76044FC7:
        cisloDalkac = 10;
        break;
      // backspace
      case 0x76044FFE: {
        if ((x > 0) && (cislic > 0)) {
          backspace = true;
          vysledek = vysledek / 10;
          x = x - 1;
          cislic = cislic - 1;
          lcd.setCursor(x, y);
          lcd.print(" ");
          lcd.setCursor(x, y);
        }
        break;
      }
      // enter
      case 0x76044FDE:
      case 0x76044FF4:
        enter = true;
      }
      if (!enter && !backspace && (cislic < 4)) {
        lcd.print(cisloDalkac);
        x = x + 1; // posun kurzor doprava
        vysledek = vysledek * 10 + cisloDalkac;
        cislic = cislic + 1;
      }
      irrecv.resume(); // nacti dalsi hodnotu
    }
  } while (!enter); // dokud jsi nedostal enter
  return vysledek; //vrat, co jsi nacetl (cislo)
}

// porovna zadane cislo se spravnym vysledkem
// spravnyVysledek = kolik to melo byt
// x = pozice na LCD
void porovnej(int spravnyVysledek, int x) {
  int vysledek = ctiDalkac(x, 1);
  //  Serial.println(vysledek);
  //  Serial.println(spravnyVysledek);
  //  Serial.println("----");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  if (spravnyVysledek != vysledek) {
    lcd.print("CH Y B A !!!");
    digitalWrite(LED_CHYBA, HIGH);
    body = body - 1;
  } else {
    lcd.print("SPRAVNE");
    digitalWrite(LED_OK, HIGH);
    body = body + 1;
  }
  // chvilku pockej
  delay(800);
  digitalWrite(LED_CHYBA, LOW);
  digitalWrite(LED_OK, LOW);
}

// vypis body
void vypisBody() {
  lcd.setCursor(12, 0);
  lcd.print("   ");
  lcd.setCursor(12, 0);
  lcd.print(body);
}

// vypis priklad
String vypisPriklad(int a, int b, String znak) {
  lcd.setCursor(0, 1);
  String text = "";
  text = text + a;
  text = text + znak;
  text = text + b;
  text = text + "=";
  lcd.print(text);
  return text;
}

void scitani() {
  int scitanec1 = random(max + 1);
  int scitanec2 = random(max + 1 - scitanec1);
  int soucet = scitanec1 + scitanec2;
  vypisBody();
  String text = vypisPriklad(scitanec1, scitanec2, "+");
  porovnej(soucet, text.length());
}

void odcitani() {
  int mensenec = random(max + 1);
  int mensitel = random(mensenec + 1);
  int rozdil = mensenec - mensitel;
  vypisBody();
  String text = vypisPriklad(mensenec, mensitel, "-");
  porovnej(rozdil, text.length());
}

// hlavni smycka
void loop() {
  // vymysli si nahodne, co budes zkouset, zda priklad na scitani nebo odcitani
  int co = random(2);
  if (co == 0) {
    scitani();
  } else {
    odcitani();
  }
  // vymazani casti displeje
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
