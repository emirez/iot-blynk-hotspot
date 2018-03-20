#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <math.h>

char auth[] = "193a526bfebf47cc869514d7a6dc3c30";
char ssid[] = "Eren's iPhone";
char pass[] = "27081992";

#define BLYNK_PRINT Serial
#define BUT1 D6
#define LED1 D3
#define POT1 A0
#define PIN_UPTIME V1

BlynkTimer timer;

// LED Port
BLYNK_WRITE(0)
{
    if (param.asInt()) {
        digitalWrite(LED1, HIGH);
    } else {
        digitalWrite(LED1, LOW);
    }
}
// Potentiometer and Button Port
void myTimerEvent()
{
    Blynk.virtualWrite(V1, analogRead(POT1));
    Blynk.virtualWrite(V2, digitalRead(BUT1));
}

// Setup Func
void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    pinMode(LED1, OUTPUT);
    pinMode(BUT1, INPUT);
    pinMode(POT1, INPUT);
    timer.setInterval(1000L, myTimerEvent);
}
// Loop Func
void loop()
{
    Blynk.run();
    timer.run();
}
