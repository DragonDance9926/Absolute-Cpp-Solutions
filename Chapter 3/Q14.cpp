#include <iostream>
#define ITER 50 
using namespace std;

double sqrt(double n){
    double guess = n/2;
    double r;
    for (int i = 0;i < ITER;i++){
        r = n / guess;
        guess = (guess + r) / 2;
    }
    return guess;
}

int main(){
    bool running = true;
    double num;
    do{
        cout << "Enter a number: ";
        cin >> num;
        if (num < 0){
            cout << "Invalid number\n";
        }
        else{
            cout << "Square root of " << num << " is " << sqrt(num) << "\n";
            cout << "Do you want to continue? (y/n): ";
            char c;
            cin >> c;
            if (c == 'n'){
                running = false;
            }
        }
    }while (running);
    return 0;
}