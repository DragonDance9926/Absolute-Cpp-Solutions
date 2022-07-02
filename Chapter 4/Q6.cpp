#include <iostream>
using namespace std;

void input(int& l1,int& l2,int& choice);
void convert(int l1,int l2,int& m1,int& m2,int& choice);
void output(int m1,int m2,int& choice);
int main(){
    int l1,l2,choice;
    int m1,m2;
    bool running = true;
    while (running){
        input(l1,l2,choice);
        convert(l1,l2,m1,m2,choice);
        output(m1,m2,choice);
        cout << "Do you want to continue? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}

void input(int& l1,int& l2,int& choice){
    cout << "1-Meters-Centimeters to Feet-Inches\n2-Feet-Inches to Meters-Centimeters\nEnter your choice: ";
    cin >> choice;
    switch (choice){
        case 1:
            cout << "Enter the height in meters and centimeters: \n";
            cin >> l1 >> l2;
            break;
        case 2:
            cout << "Enter the height in feet and inches: \n";
            cin >> l1 >> l2;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}
void convert(int l1,int l2,int& m1,int& m2,int& choice){
    double totalcentimeter;
    double totalinch;
    switch (choice){
        case 1:
            //Convert meters centimetes to feet inches
            totalcentimeter = l1*100 + l2;
            //Convert centimeters to inches
            m2 = totalcentimeter/2.54;
            //Convert inches to feet
            m1 = m2/12;
            m2 %= 12;
            break;
        case 2:
            //Convert feet inches to meters centimetes
            totalinch = l1*12 + l2;
            //Convert inches to centimeters
            m2 = totalinch*2.54;
            //Convert centimeters to meters
            m1 = m2/100;
            m2 %= 100;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

void output(int m1,int m2,int& choice){
    switch (choice){
        case 1:
            cout << "The height in feet and inches is " << m1 << "." << m2 << endl;
            break;
        case 2:
            cout << "The height in meters and centimeters is " << m1 << "." << m2 << endl;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

