#include <iostream>
using namespace std;


class PrimeNum{
    private:
        int value;
        bool isPrime(int n);
    public:
        PrimeNum(int value=1);
        PrimeNum operator++();
        PrimeNum operator++(int);
        PrimeNum operator--();
        PrimeNum operator--(int);
        friend ostream &operator<<(ostream &os, const PrimeNum &p);
};

PrimeNum::PrimeNum(int value){
    this->value = value;
}
bool PrimeNum::isPrime(int n){
    if (n == 1)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}
PrimeNum PrimeNum::operator++(){
    value++;
    while (!isPrime(value)){
        value++;
    }
    return *this;
}
PrimeNum PrimeNum::operator++(int){
    PrimeNum temp = *this;
    value++;
    while (!isPrime(value)){
        value++;
    }
    return temp;
}
PrimeNum PrimeNum::operator--(){
    value--;
    while (!isPrime(value)){
        value--;
    }
    return *this;
}
PrimeNum PrimeNum::operator--(int){
    PrimeNum temp = *this;
    value--;
    while (!isPrime(value)){
        value--;
    }
    return temp;
}
ostream &operator<<(ostream &os, const PrimeNum &p){
    os << p.value;
    return os;
}
int main(){
    PrimeNum x(1123);
    for (int i = 0; i < 10; i++){
        cout << x++ << endl;
    }
}

