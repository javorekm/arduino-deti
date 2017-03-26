/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and
 * other people at the original blog post)
 * LG added by Darryl Smith (based on the JVC protocol)
 */
#include <IRremote.h>

// pin, na kterém je připojen infra sensor
int RECV_PIN = 13;

// nastartovani IR knihovny
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);  // konzole, kam se pisou vysledky
  irrecv.enableIRIn(); // nastartovani IR prijimace
}

void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  } else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  } else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  } else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  } else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  } else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  } else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  } else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  } else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  } else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    } else {
      Serial.write('-');
      Serial.print((unsigned long)results->rawbuf[i] * USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    // vypis, co jsi prijal, co jsi rozpoznal
    dump(&results);

    // tady jsme si zapisovali nase kody z dalkoveho ovladace k mikrovezi Aiwa
    switch (results.value) {
    case 0x76044FD4:
      Serial.println("NULA");
      break;
    case 0x76044FE0:
      Serial.println("JEDNICKA");
      break;
    case 0x76044FD0:
      Serial.println("DVOJKA");
      break;
    case 0x76044FF0:
      Serial.println("TROJKA");
      break;
    case 0x76044FC8:
      Serial.println("CTYRKA");
      break;
    case 0x76044FE8:
      Serial.println("PETKA");
      break;
    case 0x76044FD8:
      Serial.println("SESTKA");
      break;
    case 0x76044FF8:
      Serial.println("SEDMICKA");
      break;
    case 0x76044FC4:
      Serial.println("OSMICKA");
      break;
    case 0x76044FE4:
      Serial.println("DEVITKA");
      break;
    case 0x76044FC7:
      Serial.println("DESITKA");
      break;
    case 0x76044FDE:
    case 0x76044FF4:
      Serial.println("ENTER");
      break;
    case 0x76044FFE:
      Serial.println("DELETE");
      break;
    }
    irrecv.resume(); // prijmi dalsi hodnotu
  }
}
