#include <Wire.h>

const int wingAddr = 69;

void setup() {
    Wire.begin();
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