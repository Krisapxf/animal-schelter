#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"


using namespace std;
class Schelter;

class Owner {
private:
    string name;
    string surname;
    int age;
    string address;
    string phoneNumber;
    vector<Animal> animals;
    Schelter *schelter=nullptr;

public:
    Owner();
    Owner(string name, string surname, int age, string phoneNumber, vector<Animal> animals, Schelter *schelter);
    void addAnimal(Animal animal);
    string getName();
    string getSurname();
    vector<Animal> getAnimals();
    Animal getAnimal(Spicies species, string name, int age, float weight);
    void print();
    void adopt(Animal animal);
    void unadopt(Animal animal);
};

