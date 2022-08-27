#include <Wire.h>

//CHANGE ANALOG TO #DEFINE

//Declare fader inputs
#define GM A6;
#define fader1 A15;
#define fader2 A14;
#define fader3 A13;
#define fader4 A12;
#define fader5 A11;

//Declare fader controls
const int Fdr1Play = 19;
const int Fdr1Pause = 20;
const int Fdr1Bump = 21;
const int Fdr2Play = 18;
const int Fdr2Pause = 17;
const int Fdr2Bump = 16;
const int Fdr3Play = 15;
const int Fdr3Pause = 14;
const int Fdr3Bump = 13;
const int Fdr4Play = 12;
const int Fdr4Pause = 11;
const int Fdr4Bump = 10;
const int Fdr5Play = 9;
const int Fdr5Pause = 8;
const int Fdr5Bump = 7;

//Declare encoders
#define encA A2;
#define encB A3;
#define encC A4;
#define encD A5;
#define encE A7;
#define encF A8;
#define encX A9;
#define encY A10;

//Page controls
const int pgUp = 47;
const int pgDn = 46;

const int MCUI2C = 0x0E;

void WifiTansmit() {

}

void setup() {

}

void loop() {
    
}