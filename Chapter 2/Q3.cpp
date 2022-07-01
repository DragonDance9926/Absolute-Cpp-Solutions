#include<iostream>
using namespace std;
int main(){
    int dollars;
    int chocolate = 0;
    cout << "Enter the number of dollars: $";
    cin >> dollars;
    chocolate = dollars;
    int coupons = dollars;
    while (coupons > 7){
        coupons -= 7;
        chocolate++;
        coupons++;
    }
    cout << "You will get " << chocolate << " chocolate bars." << endl;
}