#pragma once 
#include <string>
#include <iostream>
#include "Animal.h"
using namespace std;


class Cat: public Animal {
    private:
        string color;
        bool isTrained;
        string voice= "Meow";

    public:
        Cat();
        Cat(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isTrained);
        string getColor();
        bool getIsTrained();
        void setColor(string color);
        void setIsTrained(bool isTrained);
};