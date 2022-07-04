#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double birthday_paradox(int n)
{
    //Find the probability of having the same birthday as someone else
    //in a group of n people.
    return 1- pow(1-1.0/365, ((n*(n-1))/2));
}


int main(){
    int match = 0;
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    double sum = birthday_paradox(n);
    cout << sum << endl;
    return 0;
}