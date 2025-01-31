#pragma once

#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

class Bird : public Animal {
private:
    string color;
    bool canFly;
    string voice = "Chirp";

public:
    Bird();
    Bird(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool canFly);
    
    string getColor();
    bool getCanFly();
    void setColor(string color);
    void setCanFly(bool canFly);
};
