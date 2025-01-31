#include "Dog.h"

Dog::Dog() : Animal(), color("unknown"), isTrained(false) {}

Dog::Dog(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isTrained)
    : Animal(spicies, name, age, weight, health, isAvailableToAdopt), color(color), isTrained(isTrained) {}

string Dog::getColor() {
    return color;
}

bool Dog::getIsTrained() {
    return isTrained;
}

void Dog::setColor(string color) {
    this->color = color;
}

void Dog::setIsTrained(bool isTrained) {
    this->isTrained = isTrained;
}
