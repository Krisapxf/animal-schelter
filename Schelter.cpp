#include "Schelter.h"
#include <iostream>
#include <fstream>

Schelter::Schelter() {
    this->owners = {};
    this->animals = {};
    this->history = {};
}

Schelter::Schelter(vector<Owner> owners, vector<Animal> animals, vector<Action> history) {
    this->owners = owners;
    this->animals = animals;
    this->history = history;
}

void Schelter::addOwner(Owner owner) {
    owners.push_back(owner);
    updateHistory2(TypeOfAction::addOwner, owner);
}

void Schelter::addAnimal(Animal animal) {
    animals.push_back(animal);
    updateHistory1(TypeOfAction::addAnimal, animal);
}

void Schelter::removeOwner(string name, string surname) {
    for (size_t i = 0; i < owners.size(); i++) {
        if (owners[i].getName() == name && owners[i].getSurname() == surname) {
            owners.erase(owners.begin() + i);
            updateHistory2(TypeOfAction::removeOwner, owners[i]);
            return;
        }
    }
}

void Schelter::removeAnimal(Spicies spicies, string name, int age, float weight) {
    for (size_t i = 0; i < animals.size(); i++) {
        if (animals[i].getSpicies() == spicies && animals[i].getName() == name && animals[i].getAge() == age && animals[i].getWeight() == weight) {
            animals.erase(animals.begin() + i);
            updateHistory1(TypeOfAction::removeAnimal, animals[i]);
            return;
        }
    }
}

void Schelter::showAvailableToAdopt() {
    for(size_t i = 0; i < animals.size(); i++) {
        if (animals[i].getIsAvailableToAdopt()) {
            animals[i].print();
        }
    }
}

Animal Schelter::getAnimal(Spicies spicies, string name, int age, float weight) {
    for (auto& animal : animals) {
        if (animal.getSpicies() == spicies && animal.getName() == name && animal.getAge() == age && animal.getWeight() == weight) {
            return animal;
        }
    }
    return Animal();
}

void Schelter::showHistory() {
    if (history.empty()) {
        cout << "No history available!" << endl;
        return;
    }

    for (auto& action : history) {
        cout << "--***********-----" << endl;
        action.print();
    }
}


vector <Action> Schelter::getHistory() {
    return history;
}

vector <Owner> Schelter::getOwners() {
    return owners;
}

void Schelter::updateHistory(TypeOfAction typeOfAction, Animal animal, Owner &owner) {
    Action action(typeOfAction, animal, &owner);
    history.push_back(action);
}

void Schelter::updateHistory1(TypeOfAction typeOfAction, Animal animal) {
    Action action(typeOfAction, animal);
    history.push_back(action);
}

void Schelter::updateHistory2(TypeOfAction typeOfAction, Owner &owner) {
    Action action(typeOfAction, owner);
    history.push_back(action);
}

void Schelter::printEveryAnimal() {
    for (auto& animal : animals) {
        animal.print();
    }
}

vector <Animal> Schelter::getAnimals() {
    return animals;
}

void Schelter::printEveryOwner() {
    for (auto& owner : owners) {
        owner.print();
    }
}

void Schelter::searchAnimalBySpecies(Spicies spicies) {
    for (auto& animal : animals) {
        if (animal.getSpicies() == spicies) {
            animal.print();
        }
    }
}

void Schelter::searchAnimalByAge(int age) {
    for (auto& animal : animals) {
        if (animal.getAge() == age) {
            animal.print();
        }
    }
}

void Schelter::searchAnimalByHealth(Health health) {
    for(size_t i = 0; i < animals.size(); i++) {
        if (animals[i].getHealth() == health) {
            animals[i].print();
        }
    }
}

int Schelter::writeAnimalInfoToFile(Animal animal, string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << "Species: " << animal.getSpicies() << endl;
        file << "Name: " << animal.getName() << endl;
        file << "Age: " << animal.getAge() << endl;
        file << "Weight: " << animal.getWeight() << endl;
        file << "Health: " << animal.getHealth() << endl;
        file << "Is available to adopt: " << (animal.getIsAvailableToAdopt() ? "Yes" : "No") << endl;
        file.close();
        return 1;
    } else {
        cout << "Unable to open file" << endl;
        return 0;
    }
}
