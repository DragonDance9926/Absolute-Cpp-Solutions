#include <iostream>
using namespace std;
int main(){
    double weight;
    double met;
    double minutes;
    double calories;
    cout << "Enter weight in pounds" << endl;
    cin >> weight;
    cout << "Enter MET" << endl;
    cin >> met;
    cout << "Enter minutes of exercise" << endl;
    cin >> minutes;
    //convert pounds to kilograms
    weight = weight * 0.453592;
    calories = 0.0175 * weight * met * minutes;
    cout << "Calories burned:" << calories << endl;
    return 0;
}