#include <iostream>
#include <string>
#include "Q4.h"
using namespace std;
namespace DragonPerson{
    Person::Person(){
        name = "";
    }
    Person::Person(std::string name){
        this->name = name;
    }
    Person::Person(const Person& other){
        name = other.name;
    }
    std::string Person::getName() const{
        return name;
    }
    Person& Person::operator=(const Person& other){
        name = other.name;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Person& p){
        os << "Name: " << p.name << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Person& p){
        cout << "Enter name: ";
        is >> p.name;
        return is;
    }
};

namespace CarClass{
    Vechicle::Vechicle(){
        manifacturer = "";
        cyclinders = 0;
        owner = DragonPerson::Person();
    }
    Vechicle::Vechicle(std::string manifacturer, int cyclinders, DragonPerson::Person owner){
        this->manifacturer = manifacturer;
        this->cyclinders = cyclinders;
        this->owner = owner;
    }
    Vechicle::Vechicle(const Vechicle& other){
        manifacturer = other.manifacturer;
        cyclinders = other.cyclinders;
        owner = other.owner;
    }
    std::string Vechicle::getManifacturer() const{
        return manifacturer;
    }
    int Vechicle::getCyclinders() const{
        return cyclinders;
    }
    DragonPerson::Person Vechicle::getOwner() const{
        return owner;
    }
    Vechicle& Vechicle::operator=(const Vechicle& other){
        manifacturer = other.manifacturer;
        cyclinders = other.cyclinders;
        owner = other.owner;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Vechicle& v){
        os << "Manifacturer: " << v.manifacturer << endl;
        os << "Cyclinders: " << v.cyclinders << endl;
        os << "Owner: " << v.owner << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Vechicle& v){
        cout << "Enter manifacturer: ";
        is >> v.manifacturer;
        cout << "Enter cyclinders: ";
        is >> v.cyclinders;
        cout << "Enter owner: ";
        is >> v.owner;
        return is;
    }
    Tractor::Tractor(){
        loadCapacity = 0;
        towCapacity = 0;
    }
    Tractor::Tractor(std::string manifacturer, int cyclinders, DragonPerson::Person owner, double loadCapacity, int towCapacity) : Vechicle(manifacturer, cyclinders, owner){
        this->loadCapacity = loadCapacity;
        this->towCapacity = towCapacity;
    }
    Tractor::Tractor(const Tractor& other){
        loadCapacity = other.loadCapacity;
        towCapacity = other.towCapacity;
        Vechicle::operator=(other);
    }
    double Tractor::getLoadCapacity() const{
        return loadCapacity;
    }
    int Tractor::getTowCapacity() const{
        return towCapacity;
    }
    Tractor& Tractor::operator=(const Tractor& other){
        loadCapacity = other.loadCapacity;
        towCapacity = other.towCapacity;
        Vechicle::operator=(other);
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Tractor& t){
        os << t;
        os << "Load capacity: " << t.loadCapacity << endl;
        os << "Tow capacity: " << t.towCapacity << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Tractor& t){
        is >> t;
        cout << "Enter load capacity: ";
        is >> t.loadCapacity;
        cout << "Enter tow capacity: ";
        is >> t.towCapacity;
        return is;
    }
};