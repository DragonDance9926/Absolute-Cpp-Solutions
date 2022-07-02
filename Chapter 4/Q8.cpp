#include <iostream>
using namespace std;


void input(int& kilograms, int& grams);
void convert(int kilograms, int grams, int& pounds, int& ounces);
void output(int pounds, int ounces);

int main(){
    int kilograms, grams;
    int pounds, ounces;
    bool running = true;
    while (running){
        input(kilograms, grams);
        convert(kilograms, grams, pounds, ounces);
        output(pounds, ounces);
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}

void input(int& kilograms, int& grams){
    cout << "Enter the weight in kilograms and grams: \n";
    cin >> kilograms >> grams;
}
void convert(int kilograms, int grams, int& pounds, int& ounces){
    double totalgrams;
    totalgrams = kilograms*1000 + grams;
    ounces = totalgrams/28.35;
    pounds = ounces/16;
    ounces %= 16;
}
void output(int pounds, int ounces){
    cout << "The weight in pounds and ounces is: " << pounds << " lbs " << ounces << " oz \n";
}