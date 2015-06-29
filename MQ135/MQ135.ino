/*
This sketch is struct from articles : https://hackaday.io/project/3475-sniffing-trinket/log/12363-mq135-arduino-library
Library Repository : https://github.com/GeorgK/MQ135
Author : Damrongwit Nusuk
Email : jack@racksync.com
Website : http://www.racksync.com
*/


#include "MQ135.h"
#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);

void setup()
{
  Serial.begin(9600);
  float rzero = gasSensor.getRZero();
  delay(4000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}

void loop() {
  float ppm = gasSensor.getPPM();
  delay(1000);
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
}
