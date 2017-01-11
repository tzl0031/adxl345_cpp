#include "ADXL345.h"
#include "I2Cdev.h"
#include <bcm2835.h>
#include <stdio.h>

int main(int argc, char **argv) {
  printf("ADXL345 3-axis acceleromter example program\n");
  I2Cdev::initialize();
  ADXL345 accel;
  if (accel.testConnection())
    printf("ADXL345 connection test successful\n");
  else {
    fprintf(stderr, "ADXL345 connection test failed! exiting ...\n");
    return 1;
  }
  accel.initialize();
  int16_t ax, ay, az;
  while (true) {
    accel.getAcceleration(&ax, &ay, &az);
    printf("  x_raw:  0x%04X       y_raw:  0x%04X      z_raw:  0x%04X\r", ax,
           ay, az);
    fflush(stdout);
    bcm2835_delay(200);
  }
  return 1;
}
