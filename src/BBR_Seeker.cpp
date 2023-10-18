# include "BBR_Seeker.h"

int Seeker::lectures_amount = 30;

void Seeker::Initialize(int size) {
    // Updating Value: 
    Seeker::lectures_amount = size;

    // Checking Sensor:
    Wire.begin();
    Wire.beginTransmission(Seeker::Address);
    Wire.endTransmission();

    while(Wire.available() > 0)
        Wire.read();
}

SeekerRawData Seeker::ReadRaw() {
    SeekerRawData data;
    // Requesting 2 bytes only.
    Wire.requestFrom(Seeker::Address, 2);
    while(Wire.available()) {
        int dir = Wire.read(); // Byte 1: Direction
        int strength = Wire.read(); // Byte 2: Strength
        data.dir = dir;
        data.strength = strength;
    }

    return data;
}

SeekerResult Seeker::Read() {
    SeekerResult Data;
    int size = Seeker::lectures_amount || 30;
    int buffer[size];
    int strength;

    for(int i = 0; i < size; i++) {
        SeekerRawData temp;
        temp = Seeker::ReadRaw();
        buffer[i] = temp.dir;
        strength = temp.strength;
    }

    int popular = Seeker::PopulateValues(buffer, size);
    int average = Seeker::AverageValues(buffer, size);

    Data.Direction = 0;
    Data.Direction_1 = popular;
    Data.Direction_2 = average;
    Data.Strength = strength;
    return Data;
}

SeekerResult Seeker::ReadAdvanced(int nums[], int size) {
    SeekerResult Data = Seeker::Read();
    bool isInValue = false; 
    for(int i = 0; i < size; i++) {
      if(nums[i] == Data.Direction_2)
        isInValue = true;
    }
    Data.Direction = isInValue ? Data.Direction_2 : Data.Direction_1;
    return Data;
}

int Seeker::PopulateValues(int nums[], int size) {
    int max_count = 0,
        result;

    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++)
            if(nums[i] == nums[j])
                count++;
        
        if(count > max_count) {
            max_count = count;
            result = nums[i];
        }
    }

    return result;
}

int Seeker::AverageValues(int nums[], int size) {
    double  sum = 0,
            average = 0;

    int result;
    
    for(int i = 0; i < size; i++)
        sum += nums[i];

    average = (double)(sum/size);
    result = ((int)round(average));
    return (result <= 0) ? 12 : result;
}
