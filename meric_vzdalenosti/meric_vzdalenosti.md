[← zpět na zápisky z Arduino projektů](../index.md)

# Ultrazvukové měření vzdálenosti
Jednoduchý ultrazvukový měřič vzdálenosti se zobrazováním hodnot na OLED displeji.

## Co je potřeba umět
* ovládání OLED displeje **TODO LINK**

## Foto
![](P1120530.JPG)
![](P1120533.JPG)
![](P1120534.JPG)

## Hardware
* OLED displej, v tomto projektu využíváme rozhraní I2C, např. SSD1306
* ultrazvukové čidlo HC-SR04

## Schéma zapojení


## Program
[meric_vzdalenosti.ino](meric_vzdalenosti.ino)
``` c++
{% include_relative meric_vzdalenosti.ino %}
```
## Možná vylepšení
* Při hodnotě vyšší než 4m zobrazit hlášení, že jsme mimo rozsah.
* Při vzdálenosti nad 1m zobrazovat hodnotu v metrech.

## Poznatky
