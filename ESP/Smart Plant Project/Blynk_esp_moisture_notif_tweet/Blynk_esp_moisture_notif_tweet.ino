//Blynk working with Moisture Sensor, Notification, Twitter

#define BLYNK_PRINT Serial

#include "secrets.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <time.h>

char auth[] = SECRET_AUTH; //Blynk Auth Token
char ssid[] = SECRET_SSID; //Wifi name
char pass[] = SECRET_PASS; //Wifi password

WiFiClient client;
BlynkTimer timer;

int sensorPin = 35;  
int sensorValue = 0;  
int percent = 0;

int timeoffset = -5 * 60 * 60;
int dst = 3600;

void setup()
{
  // Debug console
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  
  //Start Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.print("Connected");

  // Start Time from NTP
  configTime(timeoffset, dst, "pool.ntp.org", "time.nist.gov");

  timer.setInterval(5000L, read_data);  //Every 5 secs run the core program
  
}

void read_data(){
  //Read Moisture Value
  sensorValue = analogRead(sensorPin);
  
  //Map Moisture Value
  percent = ValuetoPercent(sensorValue);  

  //Write to Blynk
  Blynk.virtualWrite(V5, sensorValue);
  Blynk.virtualWrite(V4, percent);
  
  //Debug by printing to Serial
  Serial.print("Raw Sensor reading: ");
  Serial.println(sensorValue);

  Serial.print("Percentage converted: ");
  Serial.println(percent);

  //Tweet Moisture Value
  //Message contains: Time + Value
  tweet_value();

  //Notify if too wet or too dry
  notif();

  
}

int ValuetoPercent(int value)
{
  int percentValue = 0;
  //0 is wet and 4200 is dry
  percentValue = map(value, 4200, 0, 0, 100);   //value, lower bound, upper bound, lower bound of target, higher bound of target
  return percentValue;
  
}


void tweet_value(){
    time_t now = time(nullptr);
    String time_t = ctime(&now);
    //Serial.println(time_t);

    String message = time_t + " The moisture is at " + sensorValue;
    Serial.print(" Tweeted:  ");
    Serial.println(message);
    
    Blynk.tweet(message);
}


void notif(){
  if (sensorValue >= 3000){
    //TOO DRY
    Blynk.notify("Hurry and water your plant! It's too dry!");
    Serial.println("Notif sent: Too dry");
  }
  else if (sensorValue <= 500){
    //TOO WET
    Blynk.notify("Stop watering! Your plant is too wet!");
    Serial.println("Notif sent: Too wet");
  }
}



void loop()
{
  Blynk.run();
  timer.run();
  
}
