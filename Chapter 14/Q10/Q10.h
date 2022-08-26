#include <iostream>
#include <string>

#ifndef Q10H_H
#define Q10H_H
namespace DragonPet{
    class Pet{
        private:
            std::string name;
            std::string age;
            int weight;
        public:
            Pet();
            Pet(std::string, std::string, int);
            Pet(const Pet&);
            std::string getName() const;
            std::string getAge() const;
            int getWeight() const;
            Pet& operator=(const Pet&);
            std::string getLifeSpan();
            friend std::ostream& operator<<(std::ostream&, const Pet&);
            friend std::istream& operator>>(std::istream&, Pet&);
    };
    class Dog: public Pet{
        private:
            std::string breed;
        public:
            Dog();
            Dog(std::string, std::string, int, std::string);
            Dog(const Dog&);
            std::string getBreed() const;
            std::string getLifeSpan();
            friend std::ostream& operator<<(std::ostream&, const Dog&);
            friend std::istream& operator>>(std::istream&, Dog&);
    };
    class Rock: public Pet{
        public:
            Rock();
            Rock(std::string, std::string, int);
            Rock(const Rock&);
            std::string getLifeSpan();
            friend std::ostream& operator<<(std::ostream&, const Rock&);
            friend std::istream& operator>>(std::istream&, Rock&);
    };
    
}
#endif // !Q10H_H