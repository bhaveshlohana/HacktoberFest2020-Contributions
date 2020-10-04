#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
#include <SPI.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "8f1803207c0c4b42bbd043c458c50faa";
char ssid[] = "OpenWrt";
char pass[] = "merahhitam";

SoftwareSerial EspSerial(2, 3); // RX, TX ESP8266
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
int relayPin = 8;
int ledPin = 13;
BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8442);
  timer.setInterval(1000L, relayStatus);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void relayStatus(){
  digitalWrite(ledPin, digitalRead(relayPin));
}
