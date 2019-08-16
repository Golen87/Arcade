#ifndef TRACKER_H_INCLUDED
#define TRACKER_H_INCLUDED
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>

#define NOTE_A 27.50000
#define NOTE_A_SHARP 29.13524
#define NOTE_B 30.86771
#define NOTE_C 32.70320
#define NOTE_C_SHARP 34.64783
#define NOTE_D 36.70810
#define NOTE_D_SHARP 38.89087
#define NOTE_E 41.20344
#define NOTE_F 43.65353
#define NOTE_F_SHARP 46.24930
#define NOTE_G 48.99943
#define NOTE_G_SHARP 51.91309

#define CHANNELS 8

class Data
{
public:
    int note = 0; //the note (keys 1-88)
    int octave = 0; //the subscript number
    bool sharp; //is it sharp?
    int effect = 0; //The effect number
    int parameterX = 0; //parameter for the effect
    int parameterY = 0; //parameter for the effect

};

class Pattern
{
public:
    Data data[60];
};

class Tracker
{
public:
    Tracker();
private:
    int bpm = 120; //???
    Pattern pattern[99];

    sf::Sound channel[CHANNELS]; //all the voices

    void loadPulseWave(int c);
    void loadSquareWave(int c);
    void loadTriangle(int c);
    void loadNoise(int c);
    void loadSinWave(int c);
    void loadSample(int c);
};

#endif // TRACKER_H_INCLUDED
