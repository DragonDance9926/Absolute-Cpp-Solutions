#include <iostream>
#include<string>
#include <iomanip>
#define SIZE 12 
using namespace std;
string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
void input(double arr[]){
    for (int i = 0; i < SIZE; i++){
        cout << "The avarage of " << months[i] << " is: ";
        cin >> arr[i];
    }
}

double avarage(double arr[]){
    double sum = 0;
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    return sum/SIZE;
}

void crate_table(double arr[]){
    cout << setw(10) << "Month" << setw(10) << "Avarage" << setw(10) << "Diff" << endl;
    double avg = avarage(arr);
    for (int i = 0; i < SIZE; i++){
        cout << setw(10) << months[i] << setw(10) << arr[i] << setw(10) << arr[i] - avg << endl;
    }
}

int main(){
    double arr[SIZE];
    input(arr);
    crate_table(arr);
}