#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    private:
        double real;
        double imaginary;
        double getreal();
        double getimaginary();
    public:
        Complex(double r, double i);
        Complex(double r);
        Complex();
        friend ostream &operator<<(ostream &os, const Complex &c);
        friend istream &operator>>(istream &is, Complex &c);
        Complex operator+(Complex c);
        Complex operator-(Complex c);
        Complex operator*(Complex c);
        Complex operator/(Complex c);
        Complex operator+=(Complex c);
        Complex operator-=(Complex c);
        Complex operator*=(Complex c);
        Complex operator/=(Complex c);
        bool operator==(Complex c);
        bool operator!=(Complex c);
};

Complex::Complex(double r, double i){
    real = r;
    imaginary = i;
}
Complex::Complex(double r){
    real = r;
    imaginary = 0;
}
Complex::Complex(){
    real = 0;
    imaginary = 0;
}
double Complex::getreal(){
    return real;
}
double Complex::getimaginary(){
    return imaginary;
}
ostream &operator<<(ostream &os, const Complex &c){
    os << c.real << " + " << c.imaginary << "i";
    return os;
}
istream &operator>>(istream &is, Complex &c){
    is >> c.real >> c.imaginary;
    return is;
}
Complex Complex::operator+(Complex c){
    return Complex(real + c.real, imaginary + c.imaginary);
}
Complex Complex::operator-(Complex c){
    return Complex(real - c.real, imaginary - c.imaginary);
}
Complex Complex::operator*(Complex c){
    return Complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}
Complex Complex::operator/(Complex c){
    return Complex((real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary), (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary));
}
Complex Complex::operator+=(Complex c){
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}
Complex Complex::operator-=(Complex c){
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}
Complex Complex::operator*=(Complex c){
    real = real * c.real - imaginary * c.imaginary;
    imaginary = real * c.imaginary + imaginary * c.real;
    return *this;
}
Complex Complex::operator/=(Complex c){
    real = (real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
    imaginary = (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
    return *this;
}
bool Complex::operator==(Complex c){
    return real == c.real && imaginary == c.imaginary;
}
bool Complex::operator!=(Complex c){
    return real != c.real || imaginary != c.imaginary;
}

int main(){
    Complex c1, c2, c3;
    cout << "Enter complex number 1: ";
    cin >> c1;
    cout << "Enter complex number 2: ";
    cin >> c2;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;
    cout << "Enter complex number 3: ";
    cin >> c3;
    c1 += c3;
    cout << "c1 += c3; c1 = " << c1 << endl;
    c1 -= c3;
    cout << "c1 -= c3; c1 = " << c1 << endl;
    c1 *= c3;
    cout << "c1 *= c3; c1 = " << c1 << endl;
    c1 /= c3;
    cout << "c1 /= c3; c1 = " << c1 << endl;
    if(c1 == c2)
        cout << "c1 == c2" << endl;
    else
        cout << "c1 != c2" << endl;
}