#pragma once 
#include <string>
#include <iostream>
#include "Animal.h"
using namespace std;

class Fish: public Animal {
    private:
        string color;
        bool isSaltWater;
        string voice= "Bloop";

    public:
        Fish();
        Fish(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isSaltWater);
        string getColor();
        bool getIsSaltWater();
        void setColor(string color);
        void setIsSaltWater(bool isSaltWater);
};