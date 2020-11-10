//Check Discord

#include "discordfile.h"


#include "tempwrite.h" 
#include <WiFi.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiClient client;

const char server[] = "discordapp.com";
const int port = 443;
const String discord_webhook = SECRET_WEBHOOK;
const String discord_tts = SECRET_TTS;

HttpClient http_client;


void setup() {
   // Initialize Serial at the baud rate for ESP
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  
  
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
  discord_send("Hello World");

}

void discord_send(String content) {
  Serial.println("[HTTP] Connecting to Discord...");
  Serial.println("[HTTP] Message: " + content);
  Serial.println("[HTTP] TTS: " + discord_tts);
  http_client.post(discord_webhook, "application/json", "{\"content\":\"" + content + "\", \"tts\":" + discord_tts + "}");
  int statusCode = http_client.responseStatusCode();
  String response = http_client.responseBody();

  Serial.print("[HTTP] Status code: ");
  Serial.println(statusCode);
  Serial.print("[HTTP] Response: ");
  Serial.println(response);
}
