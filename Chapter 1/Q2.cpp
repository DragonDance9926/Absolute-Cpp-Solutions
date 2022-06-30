#include <iostream>
using namespace std;

int main(){
    const double raito = 0.001; //constant variable
    double kill; //amount of artificial sweetener needed to kill a mouse
    double ratweight; //variable for weight
    double colaweight; //variable for weight
    cout << "The amout of artificial sweetener needed to kill a mouse in gram: "; //print the text
    cin >> kill; //read the input
    cout << "Weight of rat in grams: "; //print the text
    cin >> ratweight; //read the input
    cout << "Weight of cola in grams: "; //print the text
    cin >> colaweight; //read the input
    double sweetener = colaweight * raito;
    int rat = static_cast<int>(sweetener / kill);
    cout << "Killed rat: " << rat << endl; //print the output
}