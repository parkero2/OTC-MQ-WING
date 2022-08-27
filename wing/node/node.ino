#include <Wire.h>

const int MEGA = 0x0E;
const int MCUI2C = 2B8;

void setup() {
    Wire.begin(MCUI2C);
    Serial.begin(9600);
}