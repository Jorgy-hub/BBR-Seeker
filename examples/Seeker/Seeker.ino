# include <BBR_Seeker.h>

Seeker seeker;

void setup() {
    seeker.Initialize(20);
    Serial.begin(115200);
};

void loop() {
    SeekerResult result = seeker.Read();
    int dir1 = result.Direction_1, 
        dir2 = result.Direction_2, 
        strength = result.Strength;

    Serial.print("Strength: ");
    Serial.print(strength);
    Serial.print("| Direction 1: ");
    Serial.print(dir1);
    Serial.print("| Direction 2: ");
    Serial.println(dir2);
};