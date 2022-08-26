#include<iostream>
#include<string>
#include"Q4.h"
using namespace std;

int main(){
    DragonPerson::Person owner;
    cin >> owner;
    cout << owner << endl;
    cout << "1- Define Vechicle" << endl;
    cout << "2- Define Tractor" << endl;
    cout << "3- Exit" << endl;
    int choice;
    cin >> choice;
    while(choice != 3){
        if(choice == 1){
            CarClass::Vechicle v;
            cin >> v;
            cout << v << endl;
        }
        else if(choice == 2){
            CarClass::Tractor t;
            cin >> t;
            cout << t << endl;
        }
        else{
            cout << "Invalid choice" << endl;
        }
        cout << "1- Define Vechicle" << endl;
        cout << "2- Define Tractor" << endl;
        cout << "3- Exit" << endl;
        cin >> choice;
    }
    return 0;
}