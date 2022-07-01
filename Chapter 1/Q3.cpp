#include <iostream>
using namespace std;

int main(){
    const double per = 0.076; //constant variable
    double salary; //variable for salary
    double raise; //variable for raise
    cout << "Salary: "; //print the text
    cin >> salary; //read the input
    raise = (salary / 12) * per * 6;
    cout << "Raise: " << raise << endl; //print the output
    cout << "New salary: " << salary + raise << endl; //print the output
    cout << "Monthly: " << (salary + raise) / 12 << endl; //print the output
    return 0; //return 0
}