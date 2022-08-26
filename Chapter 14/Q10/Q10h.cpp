#include <iostream>
#include <string>
#include "Q10.h"
namespace DragonPet{
    Pet::Pet(){
        name = "";
        age = "";
        weight = 0;
    }
    Pet::Pet(std::string n, std::string a, int w){
        name = n;
        age = a;
        weight = w;
    }
    Pet::Pet(const Pet& p){
        name = p.name;
        age = p.age;
        weight = p.weight;
    }
    std::string Pet::getName() const{
        return name;
    }
    std::string Pet::getAge() const{
        return age;
    }
    std::string Pet::getLifeSpan(){ 
        return "Unknown Lifespan";
    }
    int Pet::getWeight() const{
        return weight;
    }
    Pet& Pet::operator=(const Pet& p){
        name = p.name;
        age = p.age;
        weight = p.weight;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Pet& p){
        os << "Pet Name: " << p.name << std::endl;
        os << "Pet Age: " << p.age << std::endl;
        os << "Pet Weight: " << p.weight << std::endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Pet& p){
        std::cout << "Pet Name: ";
        is >> p.name;
        std::cout << "Pet Age: ";
        is >> p.age;
        std::cout << "Pet Weight: ";
        is >> p.weight;
        return is;
    }
    Dog::Dog():Pet(){
        breed = "";
    }
    Dog::Dog(std::string n, std::string a, int w, std::string b):Pet(n, a, w){
        breed = b;
    }
    Dog::Dog(const Dog& d):Pet(d){
        breed = d.breed;
    }
    std::string Dog::getBreed() const{
        return breed;
    }
    std::string Dog::getLifeSpan(){
        return getWeight() > 100 ? "Approximately 7 years" : "Approximately 13 years";
    }
    std::ostream& operator<<(std::ostream& os, const Dog& d){
        os << "Dog Name: " << d.getName() << std::endl;
        os << "Dog Age: " << d.getAge() << std::endl;
        os << "Dog Weight: " << d.getWeight() << std::endl;
        os << "Dog Breed: " << d.getBreed() << std::endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Dog& d){
        is >> static_cast<Pet&>(d);
        std::cout << "Dog Breed: ";
        is >> d.breed;
        return is;
    }
    Rock::Rock():Pet(){
        //does nothing
    }
    Rock::Rock(std::string n, std::string a, int w):Pet(n, a, w){
        //does nothing
    }
    Rock::Rock(const Rock& r):Pet(r){
        //does nothing
    }
    std::string Rock::getLifeSpan(){
        return "Thousands of years";
    }
    std::ostream& operator<<(std::ostream& os, const Rock& r){
        os << "Rock Name: " << r.getName() << std::endl;
        os << "Rock Age: " << r.getAge() << std::endl;
        os << "Rock Weight: " << r.getWeight() << std::endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Rock& r){
        is >> static_cast<Pet&>(r);
        return is;
    }
}

