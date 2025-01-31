#pragma once 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Health{
    healthy,
    sick,
    critical
};

enum Spicies{
    dog,
    cat,
    bird,
    fish,
    unknown
};

class Animal{
    private:
        Spicies spicies;
        string name;
        int age;
        float weight;
        Health health;
        bool isAvailableToAdopt;

    public:
        Animal();
        Animal(Spicies spicies, string name, int age, float weight,Health health, bool isAvailableToAdopt);
        Spicies getSpicies();
        string getName();
        int getAge();
        float getWeight();
        Health getHealth();
        bool getIsAvailableToAdopt();
        void setSpicies(Spicies spicies);
        void setName(string name);
        void setAge(int age);
        void setWeight(float weight);
        void setHealth(Health health);
        void setIsAvailableToAdopt(bool isAvailableToAdopt);
        void print();


};

