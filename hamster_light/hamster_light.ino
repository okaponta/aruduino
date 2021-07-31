const int LED = 9;
const int LIGHT_ON_BUFFER_TIME = 10;
const int LIGHT_ON_MAX_TIME = 2000;
boolean isLightOn = false;
boolean lightOnFlag = false;
int secondsDark = 0;
int secondsLightOn = 0;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {
  delay(1000);
  int val = analogRead(0);
  if (val < 400){
    roomDark();
    return;
  }
  roomBright();
}

void roomDark() {
  if (lightOnFlag) {
    // 一度暗い間に点灯済なら処理をしない
    return;
  }
  if (isLightOn) {
    if (secondsLightOn++ > LIGHT_ON_MAX_TIME) {
      lightOff();
      secondsLightOn = 0;
      lightOnFlag = true;
    }
  }
  if (secondsDark++ > LIGHT_ON_BUFFER_TIME){
    digitalWrite(LED, HIGH);
    isLightOn = true;
    secondsDark = 0;
  }
}

void roomBright() {
  lightOff();
  isLightOn = false;
  lightOnFlag = false;
  secondsLightOn = 0;
  secondsDark = 0;
}

void lightOn() {
  digitalWrite(LED, HIGH);
}

void lightOff() {
  digitalWrite(LED, LOW);
}
