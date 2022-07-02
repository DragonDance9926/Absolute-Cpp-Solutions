#include <iostream>
using namespace std;

void input(int&, int&, int&);
void convert(int, int, int&, int&, int);
void output(int, int,int);

int main(){
    int old_Weight1, old_Weight2, choice;
    int new_Weight1, new_Weight2;
    bool running = true;
    while (running){
        input(old_Weight1, old_Weight2, choice);
        convert(old_Weight1, old_Weight2, new_Weight1, new_Weight2, choice);
        output(new_Weight1, new_Weight2,choice);
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}

void input(int& old_Weight1, int& old_Weight2, int& choice){
    cout << "1-Kilograms to Pounds and Ounces\n";
    cout << "2-Pounds and Ounces to Kilograms\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice){
        case 1:
            cout << "Enter the weight in kilograms and grams: ";
            cin >> old_Weight1 >> old_Weight2;
            break;
        case 2:
            cout << "Enter the weight in pounds and ounces: ";
            cin >> old_Weight1 >> old_Weight2;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}
void convert(int old_Weight1, int old_Weight2, int& new_Weight1, int& new_Weight2, int choice){
    double totalounces;
    double totalgrams;
    switch (choice){
        case 1:
            //Kilograms and grams to Pounds and Ounces
            totalgrams = old_Weight1*1000 + old_Weight2;
            new_Weight2 = totalgrams/28.35;
            new_Weight1 = new_Weight2/16;
            new_Weight2 %= 16;
            break;
        case 2:
            //Pounds and ounces to Kilograms and grams
            totalounces = old_Weight1*16 + old_Weight2;
            new_Weight2 = totalounces*28.3495;
            new_Weight1 = new_Weight2/1000;
            new_Weight2 %= 1000;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

void output(int new_Weight1, int new_Weight2, int choice){
    switch (choice){
        case 1:
            cout << "The weight in pounds and ounces is: " << new_Weight1 << " lbs " << new_Weight2 << " oz \n";
            break;
        case 2:
            cout << "The weight in kilograms and grams is: " << new_Weight1 << " kg " << new_Weight2 << " g \n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}
    