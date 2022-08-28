#include <Wire.h>

/**
 * REFERENCE:
 * FD01100 - FADER 1 100%
 * F01Pl - FADER 1 PLAY
 * F01Pu - FADER 1 PAUSE
 * F01Bu - FADER 1 BUMP
*/

//Declare fader inputs
#define GM A6
#define fader1 A15
#define fader2 A14
#define fader3 A13
#define fader4 A12
#define fader5 A11

//Declare fader controls
const int Fdr1Play = 19;
const int Fdr1Pause = 20;
const int Fdr1Bump = 21;
const int Fdr2Play = 18;
const int Fdr2Pause = 17;
const int Fdr2Bump = 16;
const int Fdr3Play = 15;
const int Fdr3Pause = 14;
const int Fdr3Bump = 0;
const int Fdr4Play = 1;
const int Fdr4Pause = 2;
const int Fdr4Bump = 3;
const int Fdr5Play = 4;
const int Fdr5Pause = 5;
const int Fdr5Bump = 6;

const int Fdr6Play = 9;
const int Fdr6Pause = 8;
const int Fdr6Bump = 7;
const int Fdr7Play = 12;
const int Fdr7Pause = 11;
const int Fdr7Bump = 10;
const int Fdr8Play = 44;
const int Fdr8Pause = 45;
const int Fdr8Bump = 42;
const int Fdr9Play = 43;
const int Fdr9Pause = 40;
const int Fdr9Bump = 41;
const int Fdr10Play = 38;
const int Fdr10Pause = 39;
const int Fdr10Bump = 36;

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

//Select controls
const int loc = 53;
const int oddeven = 52;
const int highlight = 50;
const int single = 51;
const int fan = 48;
const int all = 49;

//Programmer controls
const int rel = 23;
const int sel = 25;
const int clr = 27;
const int shift = 26;
const int blind = 24;
const int back = 22;

//Cue controls
const int undo = 35;
const int rem = 33;
const int move = 31;
const int copy = 29;
const int set = 28;
const int inc = 30;
const int upd = 32;
const int rec = 34;

//I2C address
const int MEGA = 0x0E;
const int MCUI2C = 0x2B8;
const int BaseI2C = 0x1B39;

//Create a temp array for the values
int FaderTemps[10];
const int faders[5] = {fader1, fader2, fader3, fader4, fader5};
const String FaderNames[10] = {"F01", "F02", "F03", "F04", "F05", "F06", "F07", "F08", "F09", "F10"};
const int FaderPinMap[30] = {Fdr1Play, Fdr1Pause, Fdr1Bump, Fdr2Play, Fdr2Pause, Fdr2Bump, Fdr3Play, Fdr3Pause, Fdr3Bump, Fdr4Play, Fdr4Pause, Fdr4Bump, Fdr5Play, Fdr5Pause, Fdr5Bump, Fdr6Play, Fdr6Pause, Fdr6Bump, Fdr7Play, Fdr7Pause, Fdr7Bump, Fdr8Play, Fdr8Pause, Fdr8Bump, Fdr9Play, Fdr9Pause, Fdr9Bump, Fdr10Play, Fdr10Pause, Fdr10Bump};
const String FaderControls[30] = {"F01Pl", "F01Pa", "F01Bu", "F02Pl", "F02Pa", "F02Bu", "F03Pl", "F03Pa", "F03Bu", "F04Pl", "F04Pa", "F04Bu", "F05Pl", "F05Pa", "F05Bu", "F06Pl", "F06Pa", "F06Bu", "F07Pl", "F07Pa", "F07Bu", "F08Pl", "F08Pa", "F08Bu", "F09Pl", "F09Pa", "F09Bu", "F10Pl", "F10Pa", "F10Bu"};

//Bool to wait for nano
bool nanoWait = true;

//Create a function for recieving data on I2C
void RecData() {
    char *data[10];
    while (Wire.available()) {
        data = (char*)Wire.read();
        for (int i = 4; i < 10; i++) {
            if (String(data).startsWith(FaderNames[i])) {
                FaderTemps[i] = analogRead(faders[i]);
                TansmitUpdate(FaderNames[i] + FaderTemps[i]);
            }
        }
    }
}

void TansmitUpdate(char *dataToTran) {
    Wire.beginTransmission(MCUI2C);
    Wire.write(String(dataToTran));
    Wire.endTransmission();
    Wire.beginTransmission(BaseI2C);
    wire.write(String(dataToTran));
    Wire.endTransmission();
}

void setup() {
    Wire.begin(MEGA);
    Wire.onReceive(RecData);
    while (nanoWait);
    for (int i = 0; i < 5; i++) {
        FaderTemps[i] = analogRead(faders[i]);
    }
}

void loop() {
    for (int i = 0; i < 30; i++){ //Check for dumps, pauses and plays
        if (digitalRead(FaderPinMap[i]) == HIGH) {
            TansmitUpdate(FaderControls[i]);
        }
    }
}
