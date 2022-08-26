#include <iostream>
#include <string>
#include "Q10.h"
using namespace std;
using namespace DragonPet;
int main(){
    cout << "1- Create a Pet" << endl;
    cout << "2- Create a Dog" << endl;
    cout << "3- Create a Rock" << endl;
    cout << "4- Exit" << endl;
    int choice;
    cin >> choice;
    if(choice == 1){
        Pet p;
        cin >> p;
        cout << p;
        cout << "Lifespan: " << p.getLifeSpan() << endl;
    }
    else if(choice == 2){
        Dog d;
        cin >> d;
        cout << d;
        cout << "Lifespan: " << d.getLifeSpan() << endl;
    }
    else if(choice == 3){
        Rock r;
        cin >> r;
        cout << r;
        cout << "Lifespan: " << r.getLifeSpan() << endl;
    }
    else{
        cout << "Invalid Choice" << endl;
    }
}