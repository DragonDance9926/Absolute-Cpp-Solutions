#include <iostream>
using namespace std;

void input(int& pounds, int& ounces);
void convert(int pounds, int ounces, int& kilograms, int& grams);
void output(int kilograms, int grams);

int main(){
    int pounds, ounces;
    int kilograms, grams;
    bool running = true;
    while (running){
        input(pounds, ounces);
        convert(pounds, ounces, kilograms, grams);
        output(kilograms, grams);
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}

void input(int& pounds, int& ounces){
    cout << "Enter the weight in pounds and ounces: \n";
    cin >> pounds >> ounces;
}
void convert(int pounds, int ounces, int& kilograms, int& grams){
    double totalounces;
    totalounces = pounds*16 + ounces;
    grams = totalounces*28.3495;
    kilograms = grams/1000;
    grams %= 1000;
}
void output(int kilograms, int grams){
    cout << "The weight in kilograms and grams is: " << kilograms << " kg " << grams << "g \n";
}