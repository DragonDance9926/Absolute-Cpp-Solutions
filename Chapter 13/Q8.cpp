#include <iostream>
#include <cmath>
using namespace std;


double savings(double rate, double amount, int years){
    return amount * pow(1 + rate, years);
}

double savings_recur(double rate, double amount, int years){
    if (years == 0)
        return amount;
    else
        return savings_recur(rate, amount * (1 + rate), years - 1);
}
int main(){
    double rate, amount, years;
    cout << "Enter the interest rate: ";
    cin >> rate;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Enter the number of years: ";
    cin >> years;
    cout << "The amount after " << years << " years is " << savings(rate, amount, years) << endl;
    cout << "The amount after " << years << " years is " << savings_recur(rate, amount, years) << endl;
    return 0;
}