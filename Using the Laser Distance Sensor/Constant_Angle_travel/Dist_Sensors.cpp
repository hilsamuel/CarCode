#include <VL53L0X.h>
#include <Wire.h>

void I2C_select(int i) {
  if (i > 7) return;
  Wire.beginTransmission(0x70);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void setup_distance_sensors(VL53L0X* sensors, int n_sensors) {
  uint8_t i;
  Wire.begin();
  for (i = 0; i < n_sensors; i++) {
    I2C_select(i);
    sensors[i].init(); 
  }
}
 
void read_distance_sensors(int* distances, VL53L0X* sensors, int n_sensors) {
  uint8_t i;
  for (i = 0; i < n_sensors; i++) {
    I2C_select(i);
    distances[i] = sensors[i].readRangeSingleMillimeters();
  }
}
 
