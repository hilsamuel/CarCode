#include <VL53L0X.h>
#include <Wire.h>

void I2C_select(int);
 
void setup_distance_sensors(VL53L0X* , int );
 
void read_distance_sensors(int* , VL53L0X* , int );
