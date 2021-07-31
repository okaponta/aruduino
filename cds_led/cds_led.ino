const int LED = 9;
int val = 0;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {
  val = analogRead(0);
  if (val > 500){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
  delay(10);
}
