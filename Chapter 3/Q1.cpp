#include <iostream>

const double litertogallon = 0.264179;

double convert(double,double);


int main(){
    double liters, miles;
    bool running = true;
    do{
        std::cout << "Liters: ";
        std::cin >> liters;
        std::cout << "Miles: ";
        std::cin >> miles;
        std::cout << "Miles per gallon: " << convert(liters,miles) << "\n";
        std::cout << "Do you want to continue? (y/n): ";
        char answer;
        std::cin >> answer;
        if(answer == 'n'){
            running = false;
        }
    }while (running);
    
    return 0;
}

double convert(double liters,double miles){
    double gallons = liters * litertogallon;
    double milespergallon = miles / gallons;
    return milespergallon;
}