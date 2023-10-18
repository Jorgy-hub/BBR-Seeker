# include "BBR_Seeker.h"

Seeker seeker;

void setup() {
    seeker.Initialize(20);
    Serial.begin(115200);
};

void loop() {
    int pins[3] = {9,8,7};
    SeekerResult result = seeker.ReadAdvanced(pins, 3);
    int dir = result.Direction; 
    int strength = result.Strength;

    Serial.print("Strength: ");
    Serial.print(strength);
    Serial.print("| Direction 1: ");
    Serial.println(dir);
    delay(250);
};
