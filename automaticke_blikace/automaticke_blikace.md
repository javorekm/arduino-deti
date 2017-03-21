# Programované  blikače
Rozšířená verze ručních blikačů, jen už budeme programovat. Jednoduché vrstvení příkazů za sebou (sekvence), osahání si Arduino IDE, nahrávání programu do Arduina. Napájení Arduina z USB nebo z baterie.

Různá zapojení automatických blikačů. Základní struktura programu (nastavení v `setup()` a dokola opakovaný kód v `loop()`). Časování pomocí `delay()`, příkazy `digitalWrite()`, `pinMode()`, `HIGH`, `LOW`.

Vysvětlení, co je to `GND`, `VCC`, jaké typy napětí kde na Arduinu najdeme.

## Co je potřeba umět
Základy zapojování LED.
## Foto
Fotografie nezobrazuje přesně typ automatického blikače, který je dále popsán kódem.

![](P1360301.JPG)

## Hardware
* dostatek různě barevných LED, některé se asi spálí
* rezistory 220&nbsp;Ω - 330&nbsp;Ω
* volitelně spínače
## Schéma zapojení

## Program
[blikac.ino](blikac.ino) - kód je napsán osmiletým dítětem
``` c++
// jak dlouho ma pockat
int cas = 100;

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
```

## Možná vylepšení
* Nejrůznější variace blikačů, světla železničního přejezdu, běhající žížala

## Poznatky
V prvních chvílích není ani tak důležité, aby děti rozuměly všemu, co se v kódu píše, ale aby to blikalo.