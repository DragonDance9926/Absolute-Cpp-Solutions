#include <iostream>
#include <ctime>
using namespace std;

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
int main()
{
    unsigned long long int n;
    //Time
    clock_t start, end;
    cout << "Enter a number: ";
    cin >> n;
    start = clock();
    cout << "Fibonacci number " << n << " is " << fibonacci_iter(n) << endl;
    end = clock();
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}