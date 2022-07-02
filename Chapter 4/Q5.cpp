#include <iostream>
using namespace std;

void input(int& meter,int& centimeter);
void convert(int meter,int centimeter,int& feet,int& inches);
void output(int feet,int inches);

int main(){
    int meter,centimeter;
    int feet,inches;
    bool running = true;
    while (running){
        input(meter,centimeter);
        convert(meter,centimeter,feet,inches);
        output(feet,inches);
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}
void input(int& meter,int& centimeter){
    cout << "Enter the height in meters and centimeters: \n";
    cin >> meter >> centimeter;
}
void convert(int meter,int centimeter,int& feet,int& inches){
    double totalCentimeter = meter*100 + centimeter;
    //Convert centimeters to inches
    inches = totalCentimeter/2.54;
    //Convert inches to feet
    feet = inches/12;
    inches -= feet*12;
}
void output(int feet,int inches){
    cout << "The height in feet and inches is " << feet << "." << inches << endl;
}