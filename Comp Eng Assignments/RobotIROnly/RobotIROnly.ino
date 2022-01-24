int IRSensorRight = A5;
int LEDRight = 2;
int IRSensorLeft = A0;
int LEDLeft = 13;

void setup() {
  pinMode(IRSensorRight, INPUT);
  pinMode(LEDRight, OUTPUT);
  pinMode(IRSensorLeft, INPUT);
  pinMode(LEDLeft, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int statusSensorRight = analogRead(IRSensorRight);
  Serial.println(statusSensorRight);
  if (statusSensorRight >= 500){
    digitalWrite(LEDRight, HIGH);
  } else {
    digitalWrite(LEDRight, LOW);
  }
  delay(100);
}
