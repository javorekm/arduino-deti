[← zpět na zápisky z Arduino projektů](../index.md)

# K.I.T.T. Knight rider
Blikání LED podobné [K.I.T.T. ovi](https://www.google.com/search?q=k.i.t.t.&client=firefox-b&source=lnms&tbm=isch&sa=X&ved=0ahUKEwiKlIyOs-fSAhUDOpoKHY5WBcAQ_AUICCgB&biw=1600&bih=793) Lze naprogramovat i bez cyklů, jen je potřeba u toho více psát.

## Co je potřeba umět
Základy zapojování LED. Základní programové konstrukce pro ovládání digitálních pinů Arduina. Cykly jsou výhodou.

## Foto
![](P1130683.JPG)
![](P1130684.JPG)
![](P1130685.JPG)
![](P1130686.JPG)
![](P1130687.JPG)

## Video

<div markdown="0">
    <video controls>
        <source src="knight_rider.mp4" type="video/mp4">
        Bohužel, váš prohlížeč neumí HTML5 video. <a href="knight_rider.mp4">Přehrajte si jej jako soubor.</a>
    </video>
</div>


## Hardware
* dostatek různě barevných LED, některé se asi spálí
* rezistory 220&nbsp;Ω - 330&nbsp;Ω

## Schéma zapojení
[knight_rider.fzz](knight_rider.fzz)

[![schema](knight_rider_bb.png)](knight_rider_bb.png)

## Program
[knight_rider.ino](knight_rider.ino)
```c++
{% include_relative knight_rider.ino %}
```
## Možná vylepšení

## Poznatky
Pokud jsou pro děti cykly obtížné (a to často jsou), ničemu nevadí, když kopírují hromady kódu. Časem je to přestává bavit a samy se začínají ptát, zda se to nedá udělat nějak lépe, aby se to pořád nemusel kopírovat. Výše uvedený program s Knight riderem v této podobě dítě do 8 let nenapíše. V prvních chvílích není ani tak důležité, aby děti rozuměly všemu, vo se v kódu píše, ale aby to blikalo.
