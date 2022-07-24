#include <iostream>
#include <cmath>
using namespace std;

int hankshake(int n){
    return n * (n - 1) / 2;
}

int hankshake_recur(int n){
    if (n == 0)
        return 0;
    else
        return (n-1) +hankshake_recur(n - 1);
}

int main(){
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "The number of ways to shake hands is " << hankshake(n) << endl;
    cout << "The number of ways to shake hands is " << hankshake_recur(n) << endl;
    return 0;
}