#include <iostream>
using namespace std;

int main(){
    double recieve; //variable for recieve
    double interestrate; //variable for interestrate
    int months; //variable for months
    cout << "Recieve: "; //print the text
    cin >> recieve; //read the input
    cout << "Interest rate (%25): "; //print the text
    cin >> interestrate; //read the input
    cout << "Months: "; //print the text
    cin >> months; //read the input
    double tax = ((recieve * 100)/ (100-interestrate)) - recieve; //calculate the tax
    double total = recieve + (tax * (months / 12.0)); //calculate the total
    double monthly = total / months; //calculate the monthly
    cout << "Total: " << total << endl; //print the text
    cout << "Monthly: " << monthly << endl; //print the text
    return 0; //return 0
}