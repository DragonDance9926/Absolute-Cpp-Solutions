#include <iostream>
using namespace std;

int main(){
    int feet;
    int inches;
    cout << "Enter height in feet and inches" << endl;
    cin >> feet >> inches;
    //1 feet = 12 inches
    int additonalinches = (feet - 5) * 12 + inches;
    cout << "Ideal weight: " << 110 + additonalinches * 5 << endl;
    return 0;
}