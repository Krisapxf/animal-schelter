#include "Cat.h"

Cat::Cat() : Animal(), color("unknown"), isTrained(false) {}

Cat::Cat(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool isTrained)
    : Animal(spicies, name, age, weight, health, isAvailableToAdopt), color(color), isTrained(isTrained) {}

string Cat::getColor() {
    return color;
}

bool Cat::getIsTrained() {
    return isTrained;
}

void Cat::setColor(string color) {
    this->color = color;
}

void Cat::setIsTrained(bool isTrained) {
    this->isTrained = isTrained;
}
