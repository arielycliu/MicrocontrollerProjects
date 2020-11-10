#define BLYNK_PRINT Serial

#include "secrets.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = SECRET_AUTH;
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  Serial.print("Connected");

  
}

void loop()
{
  Blynk.run();
  int num = 100;
  Blynk.virtualWrite(V5, num);
  Serial.print(num);
  delay(1000);

  
  
}
