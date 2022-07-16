#include <iostream>
#include <cmath>
using namespace std;

class Rational{
    private:
        int numerator;
        int denominator;
        int gcd(int a, int b);
        void simplify();
    public:
        Rational(int n, int d);
        Rational(int n);
        Rational();
        friend ostream &operator<<(ostream &os, const Rational &r);
        friend istream &operator>>(istream &is, Rational &r);
        Rational operator+(Rational r);
        Rational operator-(Rational r);
        Rational operator*(Rational r);
        Rational operator/(Rational r);
        Rational operator+=(Rational r);
        Rational operator-=(Rational r);
        Rational operator*=(Rational r);
        Rational operator/=(Rational r);
        bool operator==(Rational r);
        bool operator!=(Rational r);
        bool operator<(Rational r);
        bool operator>(Rational r);
        bool operator<=(Rational r);
        bool operator>=(Rational r);
};

Rational::Rational(int n, int d){
    numerator = n;
    denominator = d;
    simplify();
}
Rational::Rational(int n){
    numerator = n;
    denominator = 1;
}
Rational::Rational(){
    numerator = 0;
    denominator = 1;
}
int Rational::gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void Rational::simplify(){
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}
ostream &operator<<(ostream &os, const Rational &r){
    os << r.numerator << "/" << r.denominator;
    return os;
}
istream &operator>>(istream &is, Rational &r){
    //Input format is numerator/denominator
    is >> r.numerator;
    is.ignore(1);
    is >> r.denominator;
    r.simplify();
    return is;
}
Rational Rational::operator+(Rational r){
    Rational result;
    result.numerator = numerator * r.denominator + denominator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.simplify();
    return result;
}
Rational Rational::operator-(Rational r){
    Rational result;
    result.numerator = numerator * r.denominator - denominator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.simplify();
    return result;
}
Rational Rational::operator*(Rational r){
    Rational result;
    result.numerator = numerator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.simplify();
    return result;
}
Rational Rational::operator/(Rational r){
    Rational result;
    result.numerator = numerator * r.denominator;
    result.denominator = denominator * r.numerator;
    result.simplify();
    return result;
}
Rational Rational::operator+=(Rational r){
    *this = *this + r;
    return *this;
}
Rational Rational::operator-=(Rational r){
    *this = *this - r;
    return *this;
}
Rational Rational::operator*=(Rational r){
    *this = *this * r;
    return *this;
}
Rational Rational::operator/=(Rational r){
    *this = *this / r;
    return *this;
}
bool Rational::operator==(Rational r){
    return numerator * r.denominator == denominator * r.numerator;
}
bool Rational::operator!=(Rational r){
    return !(*this == r);
}
bool Rational::operator<(Rational r){
    return numerator * r.denominator < denominator * r.numerator;
}
bool Rational::operator>(Rational r){
    return numerator * r.denominator > denominator * r.numerator;
}
bool Rational::operator<=(Rational r){
    return numerator * r.denominator <= denominator * r.numerator;
}
bool Rational::operator>=(Rational r){
    return numerator * r.denominator >= denominator * r.numerator;
}

int main(){
    Rational r1, r2;
    cout << "Enter two rational numbers: ";
    cin >> r1 >> r2;
    cout << "r1 + r2 = " << r1 + r2 << endl;
    cout << "r1 - r2 = " << r1 - r2 << endl;
    cout << "r1 * r2 = " << r1 * r2 << endl;
    cout << "r1 / r2 = " << r1 / r2 << endl;
    cout << "r1 += r2 = " << (r1 += r2) << endl;
    cout << "r1 -= r2 = " << (r1 -= r2) << endl;
    cout << "r1 *= r2 = " << (r1 *= r2) << endl;
    cout << "r1 /= r2 = " << (r1 /= r2) << endl;
    cout << "r1 == r2 = " << ((r1 == r2) ? "True":"False") << endl;
    cout << "r1 != r2 = " << ((r1 != r2) ? "True":"False") << endl;
    cout << "r1 < r2 = " << ((r1 < r2) ? "True":"False") << endl;
    cout << "r1 > r2 = " << ((r1 > r2) ? "True":"False") << endl;
    cout << "r1 <= r2 = " << ((r1 <= r2) ? "True":"False") << endl;
    cout << "r1 >= r2 = " << ((r1 >= r2) ? "True":"False") << endl;
    return 0;
}