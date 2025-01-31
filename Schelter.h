#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "Owner.h"
#include "Animal.h"
#include "Action.h"

using namespace std;

class Schelter {
private:
    vector<Owner> owners;
    vector<Animal> animals;
    vector<Action> history;

public:
    Schelter();
    Schelter(vector<Owner> owners, vector<Animal> animals, vector<Action> history);
    void addOwner(Owner owner);
    void addAnimal(Animal animal);
    void removeOwner(string name, string surname);
    void removeAnimal(Spicies species, string name, int age, float weight);
    void updateHistory(TypeOfAction typeOfAction, Animal animal, Owner &owner);
    void updateHistory1(TypeOfAction typeOfAction, Animal animal);
    void updateHistory2(TypeOfAction typeOfAction, Owner &owner); 
    Animal getAnimal(Spicies spicies, string name, int age, float weight);
    vector <Action> getHistory();
    void printEveryOwner();
    vector <Animal> getAnimals();
    void printEveryAnimal();
    void showAvailableToAdopt();
    void showHistory();
    void searchAnimalBySpecies(Spicies species);
    void searchAnimalByAge(int age);
    void searchAnimalByHealth(Health health);
    int writeAnimalInfoToFile(Animal animal, string fileName);
    vector <Owner> getOwners();

};

