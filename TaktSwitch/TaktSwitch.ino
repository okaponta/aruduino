#define LED 7
#define SWITCH 13

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  if(digitalRead(SWITCH)){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
