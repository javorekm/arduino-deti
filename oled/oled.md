[← zpět na zápisky z Arduino projektů](../index.md)

# OLED
Naše první pokusy s OLED displejem. Já vím, zkratka OLED už sama o sobě v sobě obsahuje slovo displej, ale stejně tomu tak všichni říkají :-) OLED mají nízkou spotřebu a dobrý zobrazovací kontrast (svítí jen to, co svítit musí). Tak jsme taky nějaké chtěli vyzkoušet.

## Co je potřeba umět
Rozhodně se hodí vědět, jaký přesně displej vlastně držím v ruce. To usnadní jeho ovládání :-) Jinak nejsou potřeba asi žádné speciální znalosti.

## Foto
![](P1360409.JPG)

## Hardware
* OLED displej s&nbsp;I2C, např. SSD1306 ([Aliexpress](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20170322115850&SearchText=OLED+0.96))

## Jak to funguje
OLED displej, který jsme využili má úhlopříčku 0,96" a rozlišení 128×64 pixelů. Připojili jsme ho přes rozhraní I2C. To komunikuje na 2 pinech `SDA` (data) a `SCK` (clock). Tyto má Arduino Uno schováno na analogových  pinech `A4 (SDA)` a `A5 (SCK)`. 

K ovládání displeje se dále hodí knihovna [u8g](https://github.com/olikraus/u8glib/wiki/userreference). Asi nejtěžším úkolem bylo zjistit, co přesně máme za displej a jakým konstruktorem knihovnu inicializovat. Nutno říci, že na displeji samotném jsme příliš vodítek nenašli.

TODO obrázek
TODO obrázek

Někdy můžete natrefit na displej, který je dvoubarevný. Nejde většinou o plnohodnotnou dvoubarevnost, ale jistá část displeje se zobrazuje vždy pevně jednou barvou a zbytek druhou. Barvu tak nenastavujete při vykreslování jako parametr, ale volíte ji umístěním na displeji.

TODO obrázek

Následně děti projevily velký zájem zobrazovat na displej i něco jiného než jen texty různých velikostí. Postup je následující:
1. Namalovat obrázek ve svém oblíbeném grafickém programu. Je dobré si nastavit velikost papíru na rozlišení displeje (např. 128×64), abychom se pak vešli. Pokud je displej jednobarevný či falešně dvoubarevný, je dobré kreslit pouze černou na bílem podkladu. Výsledný obrázek ořezat na minimální velikost.
![](gimp_smajl.png)
1. Pomocí programu pro převod bitmapy do kódu převést obrázek. Převod je vlastně pouhý převod černých pixelů na zápis v šestnáctkové soustavě (hexa) do zdrojového kódu tak, aby bylo možné ho nahrát do displeje.
1. K převodu jsme využili program [Image2Code]() napsaný v Javě (stačí pouze soubor `Image2Code.jar`, neinstaluje se, stačí spustit). Pokud Javu na počítači zatím nemáte, je potřeba doinstalovat. Pro Linux třeba takto:
``` bash
sudo apt-get install default-jre
``` 
Program se pak spouští z příkazové řádky
``` bash
java -jar Image2Code.jar
``` 
TODO obrázek

Ale je samozřejmě možné využít i jakýkoli jiný program, např. [LCD image converter](http://www.riuson.com/lcd-image-converter), který běhá na Windows, ale je možné ho zkompilovat i pro Linux - a celkově vypadá vymazleně.

Výsledný hexa kód nakopírovat do zdrojového souboru pro Arduino. 
``` c++

```

Ještě potřebujeme vědět, jaké má obrázek rozměry. Šířku vydělíme osmi a zaokrouhlíme nahoru (= počet bajtů, které jsou na řádku), výšku pak necháme, jak je. 
``` c++

```

Knihovna [u8g](https://github.com/olikraus/u8glib/wiki/userreference) využívá koncept redraw - je potřeba neustále obnovovat stav displeje opakovaným překreslováním.
``` c++

```

## Schéma zapojení
[oled.fzz](oled.fzz)

[![oled](oled_bb.png)](oled.png)

## Program
[oled.ino](oled.ino)
``` c++
{% include_relative oled.ino %}
```

## Možná vylepšení
* Jakékoliv hrátky s displejem. Kombinace s [ručními blikači](../rucni_blikace/rucni_blikace.md), [automatickými blikači](../automaticke_blikace/automaticke_blikace.md), apod.
* Je možné vytvořit jednoduché hry, přeci jen OLED displej dává poněkud sofistikovanější zobrazovací možnosti. Spolu s tlačítky je pak možné vyhodnocovat odpovědi hráče nebo hru přímo ovládat.

## Poznatky
* Nejvíce nás potrápila detekce displeje, pak správný konstruktor, nakonec zapojení na SDA/SCK na Arduinu (nevěděl jsem, že jsou na pinech A0/A1). Ovládání přes knihovnu [u8g](https://github.com/olikraus/u8glib/wiki/userreference) bylo naopak už docela lehké.
* Náš OLED displej je sice maličký, ale je to displej a to dává všem projektům úplně jiný rozměr.
