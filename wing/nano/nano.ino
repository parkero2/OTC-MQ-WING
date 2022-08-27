#include <Wire.h>

//Declare the mega's address
const int MEGA = 0x0E; 

//Define fader pins
#define fader6 A0;
#define fader7 A1;
#define fader8 A2;
#define fader9 A3;
#define fader10 A6;

//Add fader definitions to an array
const int faders[10] = {fader6, fader7, fader8, fader9, fader10};
const string faderNames[10] = {"F06", "F07", "F08", "F09", "F10"};

int FaderTemps[10];

void setup() {
    Wire.begin();
    Serial.begin(9600);
    for (int i = 0; i < FaderTemps.length; i++) {
        FaderTemps[i] = analogRead(faders[i]); //Set the fader temps to the current analog read value
    }
}

void loop() {
    for (int i = 0; i < FaderTemps.length; i++) {
        if (analogRead(faders[i]) != FaderTemps[i]) {
            FaderTemps[i] = analogRead(faders[i]);
            //A different fader value was found, send it to the mega
            Wire.beginTransmission(MEGA);
            Wire.write(faderNames[i] + String(faders[i]));
            Wire.endTransmission();
        }
    }
}