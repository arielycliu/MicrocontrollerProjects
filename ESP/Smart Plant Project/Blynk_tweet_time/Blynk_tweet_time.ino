#define BLYNK_PRINT Serial

#include "tempwrite.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <time.h>
#include <BlynkSimpleEsp32.h>

int tweet_timer = 0;
int timeoffset = -5 * 60 * 60;
int dst = 3600;

char auth[] = SECRET_AUTH; //Blynk Auth Token
char ssid[] = SECRET_SSID; //Wifi name
char pass[] = SECRET_PASS; //Wifi password


void setup()
{
  // Debug console
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Blynk.begin(auth, ssid, pass);
  Serial.print("Connected");

  configTime(timeoffset, dst, "pool.ntp.org", "time.nist.gov");
  
}

void loop()
{
  Blynk.run();
  
  int num = (random(0, 100));
  Blynk.virtualWrite(V5, num);
  //Serial.print(num);
  delay(1000);
  
  tweet_timer = tweet_timer + 1;
  
  if (tweet_timer == 5){
    time_t now = time(nullptr);
    String time_t = ctime(&now);
    //Serial.println(time_t);

    String message = time_t + " The number is at " + num;
    Serial.print("MESSAGE:  ");
    Serial.println(message);
    
    Blynk.tweet(message);
    tweet_timer = 0;

    
  }

  // Can't send two tweets with the same message, add time
  // Only 1 tweet per 5 secs allowed
}
