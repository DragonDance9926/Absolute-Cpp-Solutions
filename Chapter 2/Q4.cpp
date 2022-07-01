#include <iostream>
#include <time.h>
#define LIMIT 1000
using namespace std;
bool isprime(int n){
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    for(int i = 3; i < LIMIT; i++){
        if (isprime(i)){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}