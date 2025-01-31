
#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"

using namespace std;

class Dog : public Animal {
    private:
        string color;
        bool isTrained;
        string voice = "Bark";

    public:
        Dog();
        Dog(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isTrained);
        string getColor();
        bool getIsTrained();
        void setColor(string color);
        void setIsTrained(bool isTrained);
};


