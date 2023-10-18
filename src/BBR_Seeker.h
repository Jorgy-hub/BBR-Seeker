/**
 * Seeker.h - A library for the BBR IR Seeker infrared sensor.
 * Created by Jorgy-Hub, April 19, 2023/
 * Released into the public domain.
*/
# ifndef BBR_Seeker_h
# define BBR_Seeker_h

# include "Arduino.h"
# include "Wire.h"

struct SeekerResult { 
    int Direction;
    int Direction_1;
    int Direction_2;
    int Strength;
};

struct SeekerRawData {
    int dir;
    int strength;
};

class Seeker {
    private: 
        /**
         * @brief 8 Bit I2C Address.
        */
        static const int Address = 0x10 / 2;
        /**
         * @brief This value is the amount of loops for precising values ++value = ++precision && --speed
        */
        static int lectures_amount;
        /**
         * @brief This function will go through all values and take the most repeated one.
         * @param nums[] Array of lectures given by the Sensor.
         * @param size Amount of loops per lecture.
         * @return int
        */
        static int PopulateValues(int nums[], int size);
        /**
         * @brief This function will average all of the lectures and return a precise result.
         * @param nums[] Array of lectures given by the Sensor.
         * @param size Amount of loops per lecture.
         * @return int
        */
        static int AverageValues(int nums[], int size);
        /**
         * @brief Obtain the Raw Data of the Sensor lecture from the Wire library.   
         * @return SeekerRawData
        */
        static SeekerRawData ReadRaw();
    public:
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

        /**
         * @brief Function to get the readed Values specificly selected.
         * @param pins Pins that will be selected as Direction alternative.
         * @return SeekerResult
        */
        static SeekerResult ReadAdvanced(int nums[], int size); 
};

# endif
