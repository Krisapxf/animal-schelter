#include "Fish.h"

Fish::Fish() : Animal(), color("unknown"), isSaltWater(false) {}

Fish::Fish(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isSaltWater)
    : Animal(spicies, name, age, weight, health, isAvailableToAdopt), color(color), isSaltWater(isSaltWater) {}

string Fish::getColor() {
    return color;
}

bool Fish::getIsSaltWater() {
    return isSaltWater;
}

void Fish::setColor(string color) {
    this->color = color;
}

void Fish::setIsSaltWater(bool isSaltWater) {
    this->isSaltWater = isSaltWater;
}
