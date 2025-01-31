#include "Bird.h"

Bird::Bird() : Animal(), color("unknown"), canFly(false) {}

Bird::Bird(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt, string color, bool canFly) 
    : Animal(spicies, name, age, weight, health, isAvailableToAdopt), color(color), canFly(canFly) {}

string Bird::getColor() {
    return color;
}

bool Bird::getCanFly() {
    return canFly;
}

void Bird::setColor(string color) {
    this->color = color;
}

void Bird::setCanFly(bool canFly) {
    this->canFly = canFly;
}
