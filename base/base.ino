#include <Wire.h>
#include "Wifi.h"

const int baseI2C = 1B39;

void setup() {
    Wire.begin(baseI2C);
    Serial.begin(9600);
}

void loop() {
    //Check is wingAddr is avaliable
    Wire.beginTransmission(wingAddr);
    if (Wire.endTransmission() == 0) {
        //Wing is connected to I2C bus
        while (Wire.avaliable() > 0) {
            Serial.print(Wire.read());//Read avaliable data to serial
        }
    }
    else {
        Serial.println("Wing is not avaliable");
        //Wifi config
    }
}