
int sensorPin = 35;  
int sensorValue = 0;  
int percent = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  percent = convertToPercent(sensorValue);  
  
  Serial.print("\n\nAnalog Value: ");
  Serial.println(sensorValue);
  Serial.print("\nPercent: ");
  Serial.print(percent);
  Serial.println("%");

  delay(1000);
}

int convertToPercent(int value)
{
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);   //value, lower bound, upper bound, lower bound of target, higher bound of target
  return percentValue;
  
}
