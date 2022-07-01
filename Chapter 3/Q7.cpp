#include <iostream>
#include <cmath>

double chillfactor(double,double);

int main(){
    double temp,windspeed;
    bool running = true;
    do{
        std::cout << "Enter the temperature(Celcius): ";
        std::cin >> temp;
        if (temp > 10){
            std::cout << "Temp is too high\n";
            continue;
        }
        std::cout << "Enter the wind speed (m / sec): ";
        std::cin >> windspeed;
        std::cout << "The chill factor is: " << chillfactor(temp,windspeed) << "\n";
        std::cout << "Would you like to run again? (y/n): ";
        char c;
        std::cin >> c;
        switch(c){
            case 'y':
                running = true;
                break;
            case 'n':
                running = false;
                break;
            default:
                std::cout << "Invalid input\n";
                running = false;
                break;
        }
    }while (running);
        
    return 0;
}

double chillfactor(double temp, double windspeed){
    double p = (10*sqrt(windspeed) -windspeed + 10.5)*(33 - temp);
    return 33 - (p / 23.1);
}
