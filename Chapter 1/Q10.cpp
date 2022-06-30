#include <iostream>
using namespace std;


int main(){
    const double gravity = 9.8;
    const double acceleration = 32;
    double time;
    cout << "Enter time in seconds" << endl;
    cin >> time;
    double height = 0.5 * acceleration * time * time;
    cout << "Height in feet: " << height << endl;
    return 0;
}