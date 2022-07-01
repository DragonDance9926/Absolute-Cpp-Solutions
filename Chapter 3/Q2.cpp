#include <iostream>

double inflationcalculator(double, double);


int main(){
    double newprice, oldprice;
    bool running;
    do{
        std::cout << "Old price: ";
        std::cin >> oldprice;
        std::cout << "New price: ";
        std::cin >> newprice;
        std::cout << "Inflation: " << inflationcalculator(newprice, oldprice) << "\n";
        std::cout << "Do you want to continue? (y/n): ";
        char answer;
        std::cin >> answer;
        switch (answer) {
            case 'y':
                running = true;
                break;
            case 'n':
                running = false;
                break;
            default:
                std::cout << "Invalid input.\n";
                running = false;
                break;
        }
    }while(running);
}

double inflationcalculator(double newprice,double oldprice){
    return ((newprice - oldprice) / oldprice)*100;
}