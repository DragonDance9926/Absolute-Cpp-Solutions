#include <iostream>
using namespace std;
int main(){
    const int overworkhourlimit = 40;
    const double work = 16.78;
    const double overwork = work * 1.5;
    const double social_tax = 0.06;
    const double federal_tax = 0.14;
    const double state_tax = 0.05;
    const int union_dues = 10;
    const int medical_dues = 35;
    double hours;
    int dependents;
    double gross_pay;
    double net_pay;
    cout << "Enter hours worked in week" << endl;
    cin >> hours;
    cout << "Enter number of dependents" << endl;
    cin >> dependents;
    if (hours > overworkhourlimit){
        gross_pay = (hours - overworkhourlimit) * overwork + work * overworkhourlimit;
    }
    else{
        gross_pay = hours * work;
    }
    if (dependents >= 3){
        cout << "Medical dues:" << medical_dues << endl;
    }
    cout << "Gross pay:" << gross_pay << endl;
    cout << "Social tax:" << gross_pay * social_tax << endl;
    cout << "Federal tax:" << gross_pay * federal_tax << endl;
    cout << "State tax:" << gross_pay * state_tax << endl;
    cout << "Union dues:" << union_dues << endl;
    net_pay = gross_pay - gross_pay * social_tax - gross_pay * federal_tax - gross_pay * state_tax - union_dues - (dependents >= 3 ? medical_dues : 0);
    cout << "Net pay:" << net_pay << endl;

    return 0;
}