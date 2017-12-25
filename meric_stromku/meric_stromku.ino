int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  //zelena
  pinMode(8, OUTPUT);
  //cervena
  pinMode(9, OUTPUT);
  //merak
  pinMode(10, OUTPUT);
  //cteni meraku
  pinMode(A0, INPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  delay(1000);
  sensorValue = analogRead(A0);
  digitalWrite(10, LOW);              
  Serial.print("sensor = ");                       
  Serial.println(sensorValue);
  delay(2  * 1000);
  if (sensorValue  >=  200) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(60  * 30  * 1000L);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
  }
}
 
