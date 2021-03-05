//----inculde the requried library---//
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> ////---- Wifi module library---/
#include <BlynkSimpleEsp8266.h>  //--Blynk library---///
//----define triger and echo pin-----///
#define TRIGGERPIN D1
#define ECHOPIN    D2
//---- define token, ssid and password---////
char auth[] = "rjZZzaRHBZdJl-DTt9uM5nK0WOM9Vi0k";
char ssid[] = "noobwifi_wlink";
char pass[] = "12345zxcvb";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12);
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH); /////---measure the duration or time period-------//
  distance = (duration / 2) / 29.1;  ///------convert duration to distance-----//
  Serial.print(distance);
  Serial.println("Cm");
  Blynk.virtualWrite(V5, distance); 
//--threshold distance-------//
  if (distance <=10)
  {
    ///----notify user----//
    Blynk.virtualWrite(V3, 255);
    Blynk.notify("Empty your Dustbin!!");
  }
  delay(100);

}
