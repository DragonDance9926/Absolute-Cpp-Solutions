#include<iostream>
#include <cmath>
using namespace std;
class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double, double);
        Complex(const Complex&);
        ~Complex();
        void setReal(double);
        void setImaginary(double);
        double getReal() const;
        double getImaginary() const;
        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator*(const Complex&);
        Complex operator/(const Complex&);
        Complex& operator=(const Complex&);
        Complex operator+=(double);
        Complex operator-=(double);
        Complex operator*=(double);
        Complex operator/=(double);
        Complex operator+(double);
        Complex operator-(double);
        Complex operator*(double);
        Complex operator/(double);
        friend ostream& operator<<(ostream&, const Complex&);
        friend istream& operator>>(istream&, Complex&);
        bool operator==(const Complex&);
        bool operator!=(const Complex&);
};

Complex::Complex(){
    real = 0;
    imaginary = 0;
}
Complex::Complex(double r, double i){
    real = r;
    imaginary = i;
}
Complex::Complex(const Complex& c){
    real = c.real;
    imaginary = c.imaginary;
}
Complex::~Complex(){
    real = 0;
    imaginary = 0;
}
void Complex::setReal(double r){
    real = r;
}
void Complex::setImaginary(double i){
    imaginary = i;
}
double Complex::getReal() const{
    return real;
}
double Complex::getImaginary() const{
    return imaginary;
}
Complex Complex::operator+(const Complex& c){
    return Complex(real + c.real, imaginary + c.imaginary);
}
Complex Complex::operator-(const Complex& c){
    return Complex(real - c.real, imaginary - c.imaginary);
}
Complex Complex::operator*(const Complex& c){
    return Complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}
Complex Complex::operator/(const Complex& c){
    return Complex((real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary), (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary));
}
Complex& Complex::operator=(const Complex& c){
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}
Complex Complex::operator+=(double d){
    real += d;
    return *this;
}
Complex Complex::operator-=(double d){
    real -= d;
    return *this;
}
Complex Complex::operator*=(double d){
    real *= d;
    imaginary *= d;
    return *this;
}
Complex Complex::operator/=(double d){
    real /= d;
    imaginary /= d;
    return *this;
}
Complex Complex::operator+(double d){
    return Complex(real + d, imaginary);
}
Complex Complex::operator-(double d){
    return Complex(real - d, imaginary);
}
Complex Complex::operator*(double d){
    return Complex(real * d, imaginary * d);
}
Complex Complex::operator/(double d){
    return Complex(real / d, imaginary / d);
}
ostream& operator<<(ostream& os, const Complex& c){
    os << c.real << " + " << c.imaginary << "i";
    return os;
}
istream& operator>>(istream& is, Complex& c){
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imaginary;
    return is;
}
bool Complex::operator==(const Complex& c){
    return real == c.real && imaginary == c.imaginary;
}
bool Complex::operator!=(const Complex& c){
    return real != c.real || imaginary != c.imaginary;
}

int main(){
    cout << "Enter a complex number: ";
    Complex c1;
    cin >> c1;
    cout << "Enter another complex number: ";
    Complex c2;
    cin >> c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;
    cout << "c1 == c2 ? " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 != c2 ? " << (c1 != c2 ? "true" : "false") << endl;
    cout << "Enter a real number: ";
    double d;
    cin >> d;
    cout << "c1 + d = " << c1 + d << endl;
    cout << "c1 - d = " << c1 - d << endl;
    cout << "c1 * d = " << c1 * d << endl;
    cout << "c1 / d = " << c1 / d << endl;
    cout << "c1 += d = " << (c1 += d) << endl;
    cout << "c1 -= d = " << (c1 -= d) << endl;
    cout << "c1 *= d = " << (c1 *= d) << endl;
    cout << "c1 /= d = " << (c1 /= d) << endl;
    return 0;
}

