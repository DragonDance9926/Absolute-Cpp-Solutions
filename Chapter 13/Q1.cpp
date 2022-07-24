#include <iostream>
#include <ctime>
using namespace std;

unsigned long long int fibonacci_recur(unsigned long long int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recur(n - 1) + fibonacci_recur(n - 2);
}

unsigned long long int fibonacci_iter(unsigned long long int n)
{
    unsigned long long int a = 1, b = 1, c = 1;
    for (unsigned long long int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}



int main(){
    unsigned long long int n;
    time_t start, end;
    cout << "Enter a number: ";
    cin >> n;
    start = clock();
    cout << "Fibonacci number of " << n << " is " << fibonacci_iter(n) << endl;
    end = clock();
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    start = clock();
    cout << "Fibonacci number of " << n << " is " << fibonacci_recur(n) << endl;
    end = clock();
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}