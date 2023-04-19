# Building Block Robotics IR Seeker

## Description
IR Seeker is a multi-platform 360 degree IR Seeker, suitable for Robocup Junior Soccer (Standard, Lightweight). For more advanced teams, the sensor can be programmed using the Arduino platform using the Grove I2C output.

## Installation
To use this library, first download the library file, paste it into the ``\Arduino\libraries`` directory, then open the examples folder and run the demo in the folder.
Another method to install is directly from the Arduino IDE then go to Sketch then Include Library then Add .ZIP Library and search for the compressed library.

## Example
```cpp
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
```

## Methods
```cpp
/**
 * @brief Function to initialize the Seeker.
 * @param size Amount of loops for precising values.
*/
static void Initialize(int size = 30);
/**
 * @brief Main function to get the readed Values.
 * @return SeekerResult
*/
static SeekerResult Read();
```

## History
2023/04/19 - Version 0.0.1 Released.

