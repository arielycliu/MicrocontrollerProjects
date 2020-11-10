const int tempPin =33;
int tempRaw;
float volts;
float temp;

void setup() {
  Serial.begin(115200);

}

void loop() {
  tempRaw = analogRead(tempPin);
  volts = tempRaw/1023.0;
  temp = (volts - 0.5)*100;
  Serial.print(" Temperature is at:   ");
  Serial.print(temp);
  Serial.println (" degrees C");
  delay(100);

}
