#define LED 7
#define SWITCH 13

boolean isLEDOn = false;
boolean isSwitchOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  if(digitalRead(SWITCH) && !isSwitchOn){
    if (isLEDOn){
      isLEDOn = false;
      digitalWrite(LED, LOW);
    } else {
      isLEDOn = true;
      digitalWrite(LED,HIGH);
    }
  }
  isSwitchOn = digitalRead(SWITCH);
}
