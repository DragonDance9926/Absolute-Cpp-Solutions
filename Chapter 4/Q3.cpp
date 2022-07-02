#include <iostream>
#define QUARTER 25
#define DIME 10
#define PENNY 1
using namespace std;

void cents(int,int&,int&,int&);

int main(){
    int cent,quarter,dime,penny;
    cout << "Enter the number of cents: \n";
    cin >> cent;
    cents(cent,quarter,dime,penny);
    cout << "The number of quarters is " << quarter << endl;
    cout << "The number of dimes is " << dime << endl;
    cout << "The number of pennies is " << penny << endl;
    return 0;
}

void cents(int cent,int& quarter,int& dime,int& penny){
    quarter = cent/QUARTER;
    cent = cent%QUARTER;
    dime = cent/DIME;
    cent = cent%DIME;
    penny = cent/PENNY;
}
