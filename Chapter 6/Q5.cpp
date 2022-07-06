#include <iostream>

using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;
        int gcd(int a, int b);
    public:
        void set_numerator(int n){
            numerator = n;
        }
        void set_denominator(int d){
            denominator = d;
        }
        int get_numerator(){
            return numerator;
        }
        int get_denominator(){
            return denominator;
        }
        void simplify();
        void print();
};

int Fraction::gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void Fraction::simplify(){
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

void Fraction::print(){
    cout << numerator << "/" << denominator << endl;
}


int main(){
    Fraction c;
    c.set_numerator(6);
    c.set_denominator(135);
    c.simplify();
    c.print();
    return 0;
}