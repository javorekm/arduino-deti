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
* OLED displej s I2C, např. [SSD1306](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20170322115850&SearchText=OLED+0.96)
* [ultrazvukové čidlo HC-SR04](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20170322115709&SearchText=hc-sr04)

## Jak to funguje
### Měření vzdálenosti ultrazvukem
Sensor [HC-SR04](http://www.micropik.com/PDF/HCSR04.pdf) má tyto parametry:
* Napájení: +5V DC
* Klidový proud : < 2mA
* Pracovní proud: 15mA
* Pracovní frekvence: 40 kHz
* Měřící rozsah: 2cm – 400 cm
* Rozlišení : 0,3 cm
* Měřící úhel: 15°

2 piny sensoru jsou napájení (VCC, GND), jeden je vstupní (Trigger) a jeden výstupní (Echo). 

Rychlost zvuku je asi 340 m/s = 34&nbsp;000 cm/s = 34 cm/ms = **0,034 cm/µs**  (0,034 cm za mikrosekundu). 

Na trigger pin sensoru nastavíme na 10 µs 5V, čímž vypustíme 8 ultrazvukových 40kHz vln, následně nám echo pin prozradí, kolik mikrosekund čekal na jejich odraz. Výsledná vzdálenost v cm se následně spočítá
```
s = t * v
s = t * 0,034
```
**Nesmíme ji ale zapomenout vydělit 2**, protože zvuk letěl samozřejmě k překážce a zpět.

### OLED
Pro ovládání displeje využíváme knihovnu [u8g](https://github.com/olikraus/u8glib/wiki/userreference).

## Schéma zapojení
[meric_vzdalenosti.fzz](meric_vzdalenosti.fzz)

![meric_vzdalenosti](meric_vzdalenosti_bb.png)

## Program
[meric_vzdalenosti.ino](meric_vzdalenosti.ino)
``` c++
{% include_relative meric_vzdalenosti.ino %}
```
## Možná vylepšení
* Při hodnotě vyšší než 4m zobrazit hlášení, že jsme mimo rozsah.
* Při vzdálenosti nad 1m zobrazovat hodnotu v metrech.

## Poznatky
Trochu nás potrápil protokol I2C, bylo to první setkání. Trvalo nám, než jsme přišli na to, že Uno R3 má I2C natvrdo na pinech A4 a A5. Měření nám fungovalo celkem spolehlivě do jednoho metru, hodně záleží, od čeho se ultrazvuk odráží. Pokud se zapojení udělá rozumně kompaktní, může s ním dítě oběhnout celý dům.