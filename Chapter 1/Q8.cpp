#include <iostream>
using namespace std;
int main(){
    double n;
    double guess;
    double r;
    cout << "Find the square root of a number" << endl;
    cout << "Enter a number" << endl;
    cin >> n;
    guess = n / 2;
    for (int i = 0; i < 10; i++){
        r = n / guess;
        guess = (guess + r) / 2;
    }
    cout << "Square root of " << n << " is " << guess << endl;
}