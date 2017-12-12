#define BLYNK_PRINT Serial
#define LED1 D3

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "Seeed_BME280.h"
#include <Wire.h>

char auth[] = "07cb1c39fdd34641a256c37e5f273794";
char ssid[] = "CASSINIguest";
char pass[] = "Cassini2016!";

BlynkTimer timer;
BME280 bme280;

void myTimerEvent()
{
  Blynk.virtualWrite(V0, (int)bme280.getTemperature());
  Blynk.virtualWrite(V1, bme280.getTemperature());
  Blynk.virtualWrite(V2, bme280.getHumidity());
  Blynk.virtualWrite(V3, bme280.getPressure());
}

void setup()
{
  Serial.begin(9600);
    if(!bme280.init()){
        Serial.println("Device error!");
    }
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}

