#include <iostream>
using namespace std;
long long int factorial_recur(long long int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial_recur(n - 1);
}
long long int factorial_iter(long long int n)
{
    long long int fact = 1;
    for (long long int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

long long int C(long long int n, long long int k)
{
    return factorial_iter(n) / (factorial_iter(k) * factorial_iter(n - k));
}

int main(){
    long long int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "C(" << n << ", " << k << ") = " << C(n, k) << endl;
    return 0;
}