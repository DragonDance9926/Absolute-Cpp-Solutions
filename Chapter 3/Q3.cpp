#include <iostream>
using namespace std;
double inflationcalculator(double, double, double);

int main(){
    double rate, oldprice;
    double years;
    bool running;
    do{
        cout << "Old price: ";
        cin >> oldprice;
        cout << "Inflation rate: ";
        cin >> rate;
        rate /= 100;
        cout << "Years: ";
        cin >> years;
        cout << "Estimated price: " << inflationcalculator(oldprice, rate, years) << "\n";
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        switch (answer) {
            case 'y':
                running = true;
                break;
            case 'n':
                running = false;
                break;
            default:
                cout << "Invalid input.\n";
                running = false;
                break;
        }
    }while(running);
    return 0;
}

double inflationcalculator(double oldprice, double rate, double years){
    double newprice = oldprice;
    for(int i = 0;i < years;i++){
        newprice += newprice * rate;
    }
    return newprice;
}