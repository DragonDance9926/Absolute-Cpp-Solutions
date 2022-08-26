#include <iostream>
#include <string>
#include <vector>
#include "Q6.h"
using namespace std;
using namespace Pay;
int main(){
    vector<CreditCardPayment> v;
    vector<CashPayment> vc;
    while (true){
        cout << "1-Credit Card Payment" << endl;
        cout << "2-Cash Payment" << endl;
        cout << "3-Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1){
            CreditCardPayment cp;
            cin >> cp;
            v.push_back(cp);
        }
        else if (choice == 2){
            CashPayment cp;
            cin >> cp;
            vc.push_back(cp);
        }
        else if (choice == 3){
            break;
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }
    cout << "Credit Card Payments" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << "Cash Payments" << endl;
    for (int i = 0; i < vc.size(); i++){
        cout << vc[i] << endl;
    }
    return 0;
}