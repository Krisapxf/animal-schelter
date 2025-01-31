#include "Animal.h"
#include <iostream>

Animal::Animal() {
    this->spicies = Spicies::unknown;
    this->name = "unknown";
    this->age = 0;
    this->weight = 0;
    this->health = Health::healthy;
    this->isAvailableToAdopt = false;
}

Animal::Animal(Spicies spicies, string name, int age, float weight, Health health, bool isAvailableToAdopt) {
    this->spicies = spicies;
    this->name = name;
    this->age = age;
    this->weight = weight;
    this->health = health;
    this->isAvailableToAdopt = isAvailableToAdopt;
}

// Gettery
Spicies Animal::getSpicies() { return spicies; }
string Animal::getName() { return name; }
int Animal::getAge() { return age; }
float Animal::getWeight() { return weight; }
Health Animal::getHealth() { return health; }
bool Animal::getIsAvailableToAdopt() { return isAvailableToAdopt; }

// Settery
void Animal::setSpicies(Spicies spicies) { this->spicies = spicies; }
void Animal::setName(string name) { this->name = name; }
void Animal::setAge(int age) { this->age = age; }
void Animal::setWeight(float weight) { this->weight = weight; }
void Animal::setHealth(Health health) { this->health = health; }
void Animal::setIsAvailableToAdopt(bool isAvailableToAdopt) { this->isAvailableToAdopt = isAvailableToAdopt; }

void Animal::print() {
    cout << " Species: " << spicies ;
    cout << " Name: " << name ;
    cout << " Age: " << age ;
    cout << " Weight: " << weight;
    cout << " Health: " << health;
    cout << " Available to adopt: " << (isAvailableToAdopt ? "Yes" : "No")<<endl;
}

