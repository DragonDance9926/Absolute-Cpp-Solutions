#include <iostream>
using namespace std;
int main(){
    int months = 0;
    double rate;
    double cost;
    double debt;
    double interest = 0;
    double monthly_payment;
    double monthly_interest;
    double monthly_debt;
    cout << "Enter the cost of the item: ";
    cin >> cost;
    cout << "Enter the rate of interest: ";
    cin >> rate;
    cout << "Enter the monthly payment: ";
    cin >> monthly_payment;
    rate /= 100;
    debt = cost;
    while (debt > 0 && months < 100){
        monthly_interest = debt * rate;
        monthly_debt = monthly_payment - monthly_interest;
        debt -= monthly_debt;
        interest += monthly_interest;
        months++;
        cout << "Month " << months << ": " << monthly_interest << " interest, " << monthly_debt << " debt" << endl;
    }
    cout << "It will take " << months << " months to pay off the loan." << endl;
    cout << "Total interest paid: " << interest << endl;
    return 0;
}