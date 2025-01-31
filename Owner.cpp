#include "Owner.h"
#include <iostream>
#include "Schelter.h"

Owner::Owner() {
    this->name = "unknown";
    this->surname = "unknown";
    this->age = 0;
    this->phoneNumber = "unknown";
    this->animals = {};
    this->schelter = nullptr; 
}

Owner::Owner(string name, string surname, int age, string phoneNumber, vector<Animal> animals, Schelter* schelter) {
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->animals = animals;
    this->schelter = schelter; 
}

void Owner::addAnimal(Animal animal) {
    animals.push_back(animal);
}

string Owner::getName() { return name; }
string Owner::getSurname() { return surname; }
vector<Animal> Owner::getAnimals() { return animals; }

Animal Owner::getAnimal(Spicies spicies, string name, int age, float weight) {
    for (auto& animal : animals) {
        if (animal.getSpicies() == spicies && animal.getName() == name && animal.getAge() == age && animal.getWeight() == weight) {
            return animal;
        }
    }
    return Animal(); 
}

void Owner::print() {
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "Phone number: " << phoneNumber << endl;
    cout << "Animals: " << endl;
    for (auto& animal : animals) {
        animal.print();
    }
}

void Owner::adopt(Animal animal) {
    if (animal.getIsAvailableToAdopt()) {
        animal.setIsAvailableToAdopt(false);
        if (schelter) { 
            schelter->updateHistory(TypeOfAction::adopt, animal, *this);
        }
    }
    animals.push_back(animal);
}

void Owner::unadopt(Animal animal) {
    for (size_t i = 0; i < animals.size(); i++) {
        if (animals[i].getSpicies() == animal.getSpicies() && animals[i].getName() == animal.getName() && animals[i].getAge() == animal.getAge() && animals[i].getWeight() == animal.getWeight()) {
            animals.erase(animals.begin() + i);
            if (schelter) {
                schelter->updateHistory(TypeOfAction::unadopt, animal, *this);
            }
            return;
        }
    }
}
