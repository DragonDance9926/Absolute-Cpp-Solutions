#include <iostream>
using namespace std;

int fibonacci(int n){
    int *fib = new int[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int result = fib[n];
    delete[] fib;
    return result;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci number of " << n << " is " << fibonacci(n) << endl;
    return 0;
}