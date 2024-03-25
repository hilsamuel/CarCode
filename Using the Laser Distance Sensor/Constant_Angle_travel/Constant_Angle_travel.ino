#include "Freenove_4WD_Car_for_Arduino.h"
#include <VL53L0X.h>
#include <Wire.h>
#include "Dist_Sensors.h"

#define N_DIST_SENSORS 3   // number of distance sensors attached
VL53L0X dist_sensors[N_DIST_SENSORS];  // create the distance sensors
int distances[N_DIST_SENSORS];  // an array to hold the distance measurements


#define STOP_SPEED       0
#define FORWARD_SPEED      120
#define TURN_GAIN    1.5

#define LEFT_FRONT  0
#define LEFT_REAR   1
#define REAR  2



void setup() {
  Serial.begin(115200);  // to print to the serial monitor
  Serial.println("Starting");
  pinsSetup(); //set up pins
  setup_distance_sensors(dist_sensors, N_DIST_SENSORS); 
}

void loop() {

  int i, error = 0, correction, leftspeed, rightspeed;
  read_distance_sensors(distances, dist_sensors, N_DIST_SENSORS); 
  error = distances[LEFT_FRONT]- distances[LEFT_REAR]; // error means not parallel to the wall
  error -= 25; // a installed calibration offset
  correction = error * TURN_GAIN;

  if (correction < 0) {  
    leftspeed = FORWARD_SPEED - correction; 
    rightspeed = FORWARD_SPEED;  // boost the correct motor
  } else {
    leftspeed = FORWARD_SPEED; 
    rightspeed = FORWARD_SPEED + correction;  // boost the correct motor
  }

  motorRun(leftspeed, rightspeed);  // boost the correct motor

  Serial.print(correction);  
  Serial.print("   ");
  Serial.print(leftspeed);
  Serial.print("   ");
  Serial.println(rightspeed);


}

