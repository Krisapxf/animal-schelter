#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
#include "Owner.h"
#include "Schelter.h"
#include "Action.h"
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "Cat.h"
#include "Bird.h"
#include "Fish.h"
#include "Dog.h"
#include <fstream>


using namespace std;

int main(){
    Schelter schelter;
    Owner owner1("John", "Doe", 30, "123456789", {}, &schelter);
    Owner owner2("Jane", "Doe", 25, "987654321", {}, &schelter);
    Owner owner3("Jack", "Smith", 40, "456789123", {}, &schelter);
    for( int i = 0; i < 10; i++){
        Health randomHealth = static_cast<Health>(rand()%3);
        Spicies randomSpicies = static_cast<Spicies>(rand()%4);
        bool isTrained = rand()%2;

        Animal *newAnimal= nullptr;
        switch(randomSpicies){
            case dog:
                newAnimal = new Dog(randomSpicies, "Dog"+to_string(i), rand()%20, rand()%20, randomHealth, true, "Brown", isTrained);
                break;
            case cat:
                newAnimal = new Cat(randomSpicies, "Cat" +to_string(i), rand()%20, rand()%20, randomHealth, true, "Black", isTrained);
                break;
            case bird:
                newAnimal = new Bird(randomSpicies, "Bird"+to_string(i), rand()%20, rand()%20, randomHealth, true, "Yellow", isTrained);
                break;
            case fish:
                newAnimal = new Fish(randomSpicies, "Fish" +to_string(i), rand()%20, rand()%20, randomHealth, true, "Gold", isTrained);
                break;
            default:
                cout << "Unknown spicies" << endl;
                break;
        }
        schelter.addAnimal(*newAnimal);
        cout << "Animal added" <<newAnimal <<endl;

    }
    schelter.addOwner(owner1);
    schelter.addOwner(owner2);
    schelter.addOwner(owner3);
    cout << "----------------------Every Owner"<<endl;
    schelter.printEveryOwner();
    cout << "----------------------Every Animal"<<endl;
    schelter.printEveryAnimal();
    cout << "----------------------Available to adopt"<<endl;
    schelter.showAvailableToAdopt();
    cout << "----------------------Search by species"<<endl;
    schelter.searchAnimalBySpecies(dog);
    cout << "----------------------Search by age"<<endl;
    for(int i=0; i<10; i++){
        cout<< "Age: "<<i<<endl;
        schelter.searchAnimalByAge(i);
    }
    cout << "----------------------Search by health"<<endl;
    schelter.searchAnimalByHealth(healthy);
    int HowManyAnimal=schelter.getAnimals().size();
    int HowManyOwners=schelter.getOwners().size();
    srand(time(NULL));
    int randomNumber=rand()%HowManyAnimal;
    cout << "Random number: "<<randomNumber<<endl;
    int randomNumber2=rand()%HowManyOwners;
    for(int i=0; i<HowManyAnimal; i++){
        if(schelter.getAnimals()[i].getIsAvailableToAdopt()){
            cout << "Animal available to adopt: "<<endl;
            schelter.getAnimals()[i].print();
            if (randomNumber2==0){
                owner1.adopt(schelter.getAnimals()[i]);
                schelter.updateHistory(adopt, schelter.getAnimals()[i], owner1);
            }
            else if (randomNumber2==1){
                owner2.adopt(schelter.getAnimals()[i]);
                schelter.updateHistory(adopt, schelter.getAnimals()[i], owner2);
            }
            else if (randomNumber2==2){
                owner3.adopt(schelter.getAnimals()[i]);
                schelter.updateHistory(adopt, schelter.getAnimals()[i], owner3);
            }
            else
            {
                cout<< "No owner available to adopt"<<endl;
            }
            cout<<schelter.getAnimals()[i].getName()<<endl;
            cout<<schelter.getAnimals()[i].getIsAvailableToAdopt()<<endl;
            cout<< "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<< "History of actions"<<endl;
            schelter.showHistory();
            cout<< "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        }
    }
    string filename("AnimalInfo.txt");
    for(int i=0; i<HowManyAnimal; i++){
        schelter.writeAnimalInfoToFile(schelter.getAnimals()[i], filename);
    }
    //how to print the file content
    ifstream file(filename);
    string line;
    if(file.is_open()){
        while(getline(file, line)){
            cout<<line<<endl;
        }
    }else{
        cout<<"Unable to open file"<<endl;
    }
    file.close();





return 0;
}