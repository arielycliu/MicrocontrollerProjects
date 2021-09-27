const int sensorPin = A0;
const float baselineTemp = 20.0;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Values: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp){
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(8, LOW);
  }

  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(1, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(8, LOW);
  }

  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(1, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(8, LOW);
  }
  else if(temperature >= baselineTemp+6){
    digitalWrite(1, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(8, HIGH);
    
    tone(buzzer, 700);
    delay(500);
    noTone(buzzer);
    delay(500);
  }

  delay(1);

}
