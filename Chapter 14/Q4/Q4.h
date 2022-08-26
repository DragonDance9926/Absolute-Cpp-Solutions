#include <iostream>
#include <string>

#ifndef Q4_H
#define Q4_H
namespace DragonPerson{
    class Person{
        private:
            std::string name;
        public:
            Person();
            Person(std::string name);
            Person(const Person& other);
            std::string getName() const;
            Person& operator=(const Person& other);
            friend std::ostream& operator<<(std::ostream& os, const Person& p);
            friend std::istream& operator>>(std::istream& is, Person& p);
    };
};





namespace CarClass{
    class Vechicle{
        private:
            std::string manifacturer;
            int cyclinders;
            DragonPerson::Person owner;
        public:
            Vechicle();
            Vechicle(std::string manifacturer, int cyclinders, DragonPerson::Person owner);
            Vechicle(const Vechicle& other);
            std::string getManifacturer() const;
            int getCyclinders() const;
            DragonPerson::Person getOwner() const;
            Vechicle& operator=(const Vechicle& other);
            friend std::ostream& operator<<(std::ostream& os, const Vechicle& v);
            friend std::istream& operator>>(std::istream& is, Vechicle& v);
    };
    class Tractor : public Vechicle{
        private:
            double loadCapacity;
            int towCapacity;
        public:
            Tractor();
            Tractor(std::string manifacturer, int cyclinders, DragonPerson::Person owner, double loadCapacity, int towCapacity);
            Tractor(const Tractor& other);
            double getLoadCapacity() const;
            int getTowCapacity() const;
            Tractor& operator=(const Tractor& other);
            friend std::ostream& operator<<(std::ostream& os, const Tractor& t);
            friend std::istream& operator>>(std::istream& is, Tractor& t);    
    };
};
#endif // !Q4_H