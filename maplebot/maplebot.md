[← zpět na zápisky z Arduino projektů](../index.md)

# Maplebot
Pokus o vytvoření jezdícího robota reagujícího na příkazy předáváné bezdrátově, nejlépe přímo pomocí dětského programovacího jazyka. Maplebot je stále projekt _"s dětmi"_ ne jen _"pro děti"_.

---
## Robopixle
Robopixle byla náš první projekt, kde se něco pohybuje a současně, kde jsme museli vzít vrtačku. Původní verze měla být dokonce ovládaná pro jednoduchost přes infra. Ale infra jsem omylem upálil, takže další v pořadí v krabičce bylo Bluetooth. Cíl je někde na Wifi/MQTT, ale na to jsme také neměli v šuplíku vybavení. To jsou plány na další verze.


[Robopixle - ovládání přes Bluetooth z Python konzole](robopixle_bt/robopixle_bt.md)

---

## Maplebot verze 2
1. [Flash Micropythonu do NodeMCU](nodemcu_flash_micropython/nodemcu_flash.md)
1. [Konzole REPL, WebREPL AP, WebREPL klient](nodemcu_repl_webrepl/nodemcu_repl_webrepl.md)

TODO
* Základní postřehy k vývoji v Micropythonu na NodeMCU
* Sestavení podvozku robota, základní pohyb
* PID regulace pohybu
* Signalizace (ne)připojení na Wifi
* MQTT
* Scratch extension + local proxy
* Server pro propojení robota a Scratch
* Čidla (vzdálenost, barva, pohyb?)
* Displej?
