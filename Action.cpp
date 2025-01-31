#include "Action.h"
#include "Owner.h"
#include <iostream>

using namespace std;


string toString(TypeOfAction action) {
    switch (action) {
        case addAnimal: return "Add Animal";
        case addOwner: return "Add Owner";
        case adopt: return "Adopt";
        case removeAnimal: return "Remove Animal";
        case removeOwner: return "Remove Owner";
        case unadopt: return "Unadopt";
        default: return "Unknown";
    }
}

Action::Action(TypeOfAction typeOfAction, Animal animal)
    : typeOfAction(typeOfAction), animal(animal), owner(nullptr) {}

Action:: Action(TypeOfAction typeOfAction, Owner &owner)
    : typeOfAction(typeOfAction), owner(&owner) {}

Action::Action(TypeOfAction typeOfAction, Animal animal, Owner* owner)
    : typeOfAction(typeOfAction), animal(animal), owner(owner) {}

void Action::print() {
    cout << "Type of action: " << toString(typeOfAction) << endl;
    cout << "Animal: " << endl;
    animal.print();
    if (owner) {
        cout << "Owner: " << endl;
        owner->print();
    } else {
        cout << "Owner: None" << endl;
    }
}
