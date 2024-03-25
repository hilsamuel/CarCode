/**********************************************************************
  Filename    : RF24_Remote_Car.ino
  Product     : Freenove 4WD Car for UNO
  Description : A RF24 Remote Car.
  Auther      : www.freenove.com
  Modification: 2020/11/27
**********************************************************************/
#include "Freenove_4WD_Car_for_Arduino.h"
#include "RF24_Remote.h"


//RDD Add code to use the servo
#include <Servo.h>
Servo servo1;

#define NRF_UPDATE_TIMEOUT    1000

u32 lastNrfUpdateTime = 0;

void setup() {
  pinsSetup();
  if (!nrf24L01Setup()) {
    alarm(3, 2);
  }
  alarm(2, 1);  //RDD
}

void loop() {

  if (getNrf24L01Data()) {  //if radio data was received
    clearNrfFlag();
    updateCarActionByNrfRemote(); 
    lastNrfUpdateTime = millis();
  }

  if (millis() - lastNrfUpdateTime > NRF_UPDATE_TIMEOUT) {
    lastNrfUpdateTime = millis();
    resetNrfDataBuf();
    updateCarActionByNrfRemote();
  }
}

