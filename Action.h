#pragma once

#include <iostream>
#include <string>
#include "Animal.h"

class Owner;  

enum TypeOfAction {
    addAnimal,
    addOwner,
    adopt,
    removeAnimal,
    removeOwner,
    unadopt
};

class Action {
private:
    TypeOfAction typeOfAction;
    Animal animal;
    Owner* owner;

public:
    Action(TypeOfAction typeOfAction, Animal animal, Owner* owner);
    Action(TypeOfAction typeOfAction, Animal animal);
    Action(TypeOfAction typeOfAction, Owner& owner);
    void print();
};
