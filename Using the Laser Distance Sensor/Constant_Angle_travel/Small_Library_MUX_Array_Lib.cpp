// #include <VL53L0X.h>
// #include <Wire.h>
// #include "Dist_Sensors.h"

// #define N_DIST_SENSORS 3   // number of distance sensors attached
// VL53L0X dist_sensors[N_DIST_SENSORS];  // create the distance sensors
// int distances[N_DIST_SENSORS];  // an array to hold the distance measurements


// void setup() {

//   Serial.begin(115200);  // to print to the serial monitor
//   Serial.println("Starting");

//   setup_distance_sensors(dist_sensors, N_DIST_SENSORS); 
// }

// void loop() {
//   int i;
//   read_distance_sensors(distances, dist_sensors, N_DIST_SENSORS); 
 
//   for (i = 0; i < N_DIST_SENSORS; i++){
//       Serial.print(distances[i]); 
//       Serial.print("     ");
//   }
//   Serial.println(" "); 
// }
