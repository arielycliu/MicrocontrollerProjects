#include "ThingSpeak.h"
#include "tempwrite.h" 
#include <WiFi.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiClient client;

unsigned long ChannelID = SECRET_CH_ID;
const char * APIKey = SECRET_WRITE_APIKEY;

const int tempPin = 35;
int tempRaw;
float volts;
float temp;

void setup() {

  // Initialize Serial at the baud rate for ESP
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

}

void loop() {
  
  // Connecting to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

  // Get Sensor value
  tempRaw = analogRead(tempPin);
  volts = tempRaw/1023.0;         //Normalize
  temp = (volts - 0.5)*100;         // Convert from volts

  // Out print the temperature for debugging
  Serial.print("The Temperature is ");
  Serial.print(temp);
  Serial.println(" C ");

  // Write the data to ThingSpeak
  ThingSpeak.writeField(ChannelID, 1, temp, APIKey);   //Channel ID, which field, value, Write API Key

  delay(2000);    //Wait 2 secs before getting more data and updating the channel
  

}
