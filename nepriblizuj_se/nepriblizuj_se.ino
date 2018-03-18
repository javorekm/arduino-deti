#include <SPI.h>
#include <Wire.h>
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

// nastaveni pinu pro ultrazvuk
#define trigPin 13
#define echoPin 12
// nastaveni pinu pro mp3
#define rxMp3 10
#define txMp3 11

// software serial pro mp3
SoftwareSerial mySoftwareSerial(rxMp3, txMp3); 
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // seriova konzole pro testy
  Serial.begin (9600);
  // nastaveni pinu pro ultrazvuk
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // inicializace software serial
  mySoftwareSerial.begin(9600);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  //nastav hlasitost prehravace (0-30)
  myDFPlayer.volume(25);  
  // normalni equalizer
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  // prehravame z SD karty
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

long zmerVzdalenost() {
  long doba, vzdalenost;
  // PULSE ___|---|___
  // vycisti trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // posli 8 cyklu za 10 mikrosekund
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  // vypni posilani
  digitalWrite(trigPin, LOW);

  // precteme echo pin
  doba = pulseIn(echoPin, HIGH);
  //prepocet na vzdalenost
  //-----------------------------
  // rychlost zvuku = 340 m/s = 0,034 cm/us (mikrosekund)
  // t = s/v => s = t * v
  // s = cas * 0,034
  // na konci musime vzdalenost vydelit 2, protoze zvuk leti tam a zpet
  vzdalenost = (doba * 0.034) / 2;
  return vzdalenost;
}

void loop() {
  long vzdalenost = zmerVzdalenost();
  Serial.print("Vzdalenost: ")
  Serial.println(vzdalenost);
  // je treba pockat nez se prehraje zvuk, odhadujeme 2s
  int pockej = 2000;
  if ((vzdalenost < 150) && (vzdalenost >= 100)) {   // 100 - 150cm
    myDFPlayer.play(1);
    delay(pockej);
  } else if ((vzdalenost < 100) && (vzdalenost >= 50)) {   // 50 - 100 cm
    myDFPlayer.play(2);
    delay(pockej);
  } else if (vzdalenost < 50) { // pod 50cm
    myDFPlayer.play(3);
    delay(pockej);
  }
  // pokud je zde mene nez 200ms, ultrazvuk zacina zlobit
  delay(300);
}
