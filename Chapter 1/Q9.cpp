#include <iostream>
using namespace std;

int main(){
    const int redeembar = 10;
    const int redeemgumball = 3;
    int coupons;
    cout << "Enter number of coupons" << endl;
    cin >> coupons;
    int redeem = coupons / redeembar;
    coupons = coupons % redeembar;
    int redeemgum = coupons / redeemgumball;
    cout << "Number of redeemable bars: " << redeem << endl;
    cout << "Number of redeemable gumballs after spending on bars: " << redeemgum << endl;
    return 0;
}