/*
Using dynamic arrays, implement a polynomial class with polynomial addition, 
subtraction, and multiplication. 
 Discussion: A variable in a polynomial does nothing but act as a placeholder for 
the coefficients. Hence, the only interesting thing about polynomials is the array 
of coefficients and the corresponding exponent. Think about the polynomial 
x*x*x + x + 1 
 Where is the term in x*x ? One simple way to implement the polynomial class is to 
use an array of doubles to store the coefficients. The index of the array is the 
exponent of the corresponding term. If a term is missing, then it simply has a zero 
coefficient.
 There are techniques for representing polynomials of high degree with many missing terms. These use so-called sparse matrix techniques. Unless you already know 
these techniques, or learn very quickly, do not use these techniques. 
 Provide a default constructor, a copy constructor, and a parameterized constructor 
that enables an arbitrary polynomial to be constructed. 
 Supply an overloaded operator = and a destructor. 
 Provide these operations: 
 polynomial + polynomial, constant + polynomial, polynomial + constant, 
 polynomial - polynomial, constant - polynomial, polynomial - constant. 
 polynomial * polynomial, constant * polynomial, polynomial * constant, 
 Supply functions to assign and extract coefficients, indexed by exponent. 
 Supply a function to evaluate the polynomial at a value of type double . 
 You should decide whether to implement these functions as members, friends, or 
standalone functions. 
*/
#include <iostream>
#include <cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
class Polynomial{
  private:
    double *coeffs;
    double *powers;
    int size;
  public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &p);
    int getSize() const;
    double getCoeff(int i) const;
    double getPower(int i) const;
    void setCoeff(int i, double c);
    void setPower(int i, double p);
    friend double eval(const Polynomial &p, double x);
    Polynomial operator+(const Polynomial &p) const;
    Polynomial operator-(const Polynomial &p) const;
    Polynomial operator*(const Polynomial &p) const;
    Polynomial operator+(double c) const;
    Polynomial operator-(double c) const;
    Polynomial operator*(double c) const;
    Polynomial& operator=(const Polynomial &p);
    ~Polynomial();
    friend ostream &operator<<(ostream &os, const Polynomial &p);
    friend istream &operator>>(istream &is, Polynomial &p);
    void clean();
};

double eval(const Polynomial &p, double x){
  double result = 0;
  for(int i = 0; i < p.getSize(); i++){
    result += p.getCoeff(i) * pow(x, p.getPower(i));
  }
  return result;
}


Polynomial::Polynomial(){
  coeffs = new double[1];
  powers = new double[1];
  size = 1;
  coeffs[0] = 0;
  powers[0] = 0;
}
Polynomial::Polynomial(int n){
  size = n;
  coeffs = new double[n];
  powers = new double[n];
  for(int i = 0; i < n; i++){
    coeffs[i] = 0;
    powers[i] = 0;
  }
}
int Polynomial::getSize() const{
  return size;
}

Polynomial::Polynomial(const Polynomial &p){
  size = p.size;
  coeffs = new double[size];
  powers = new double[size];
  for(int i = 0; i < size; i++){
    coeffs[i] = p.coeffs[i];
    powers[i] = p.powers[i];
  }
}

Polynomial& Polynomial::operator=(const Polynomial &p){
  if(this != &p){
    delete[] coeffs;
    delete[] powers;
    size = p.size;
    coeffs = new double[size];
    powers = new double[size];
    for(int i = 0; i < size; i++){
      coeffs[i] = p.coeffs[i];
      powers[i] = p.powers[i];
    }
  }
  return *this;
}

double Polynomial::getCoeff(int i) const{
  return coeffs[i];
}
double Polynomial::getPower(int i) const{
  return powers[i];
}
void Polynomial::setCoeff(int i, double c){
  coeffs[i] = c;
}
void Polynomial::setPower(int i, double p){
  powers[i] = p;
}
Polynomial Polynomial::operator+(const Polynomial &p) const{
  int maxSize = size+p.size;
  Polynomial temp(maxSize);
  for(int i = 0; i < size; i++){
    temp.setCoeff(i, coeffs[i]);
    temp.setPower(i, powers[i]);
  }
  int j = 0;
  for(int i = size; i < maxSize; i++){
    temp.setCoeff(i, p.coeffs[j]);
    temp.setPower(i, p.powers[j]);
    j++;
  }
  return temp;
}

Polynomial Polynomial::operator-(const Polynomial &p) const{
  int maxSize = size+p.size;
  Polynomial temp(maxSize);
  for(int i = 0; i < size; i++){
    temp.setCoeff(i, coeffs[i]);
    temp.setPower(i, powers[i]);
  }
  int j = 0;
  for(int i = size; i < maxSize; i++){
    temp.setCoeff(i, -p.coeffs[j]);
    temp.setPower(i, p.powers[j]);
    j++;
  }
  return temp;
}

Polynomial Polynomial::operator*(const Polynomial &p) const{
  int maxSize = size * p.size;
  Polynomial temp(maxSize);
  for(int i = 0; i < size; i++){
    for(int j = 0; j < p.size; j++){
      temp.setCoeff(i+j, temp.getCoeff(i+j) + coeffs[i] * p.coeffs[j]);
      temp.setPower(i+j, temp.getPower(i+j) + powers[i] + p.powers[j]);
    }
  }
  return temp;
}

Polynomial Polynomial::operator+(double c) const{
  Polynomial temp(size+1);
  for(int i = 0; i < size; i++){
    temp.setCoeff(i, coeffs[i]);
    temp.setPower(i, powers[i]);
  }
  temp.setCoeff(size, c);
  temp.setPower(size, 0);
  return temp;
}
Polynomial Polynomial::operator-(double c) const{
  Polynomial temp(size+1);
  for(int i = 0; i < size; i++){
    temp.setCoeff(i, coeffs[i]);
    temp.setPower(i, powers[i]);
  }
  temp.setCoeff(size, -c);
  temp.setPower(size, 0);
  return temp;
}

Polynomial Polynomial::operator*(double c) const{
  Polynomial temp(size);
  for(int i = 0; i < size; i++){
    temp.setCoeff(i, coeffs[i] * c);
    temp.setPower(i, powers[i]);
  }
  return temp;
}


Polynomial::~Polynomial(){
  delete[] coeffs;
  delete[] powers;
}
ostream &operator<<(ostream &os, const Polynomial &p){
  for(int i = 0;i < p.getSize();i++){
    if(p.getCoeff(i) != 0){
      if(p.getPower(i) == 0){
        os << p.getCoeff(i);
      }
      else if(p.getPower(i) == 1){
        os << p.getCoeff(i) << "x";
      }
      else{
        os << p.getCoeff(i) << "x^" << p.getPower(i);
      }
      if (i != p.getSize() - 1){
        os << " + ";
      }
    }
  }
  return os;
}
istream &operator>>(istream &is, Polynomial &p){
  int n;
  cout << "Enter the number of coefficients: ";
  is >> n;
  p.size = n;
  p.coeffs = new double[n];
  p.powers = new double[n];
  for(int i = 0; i < n; i++){
    double coef,power;
    cout << "Enter coefficient: ";
    is >> coef;
    p.setCoeff(i, coef);
    cout << "Enter power: ";
    is >> power;
    p.setPower(i, power);
  }
}

void Polynomial::clean(){
  for(int i = 0; i < size; i++){
    coeffs[i] = 0;
    powers[i] = 0;
  }
}

void menu(){
  cout << "1. Add two polynomials" << endl;
  cout << "2. Subtract two polynomials" << endl;
  cout << "3. Multiply two polynomials" << endl;
  cout << "4. Add a polynomial and a constant" << endl;
  cout << "5. Subtract a polynomial and a constant" << endl;
  cout << "6. Multiply a polynomial and a constant" << endl;
  cout << "7. Print a polynomial" << endl;
  cout << "8. Clean a polynomial" << endl;
  cout << "9. Exit" << endl;
  cout << "10.Evaluate a polynomial" << endl;
}


int main(){
  Polynomial p1;
  cout << "Enter the polynomial: ";
  cin >> p1;
  int choice = 0;
  while (choice != 9){
    menu();
    cout << "Enter your choice: ";
    cin >> choice;
    Polynomial p2;
    double c;
    switch(choice){
      case 1:
        cout << "Enter the second polynomial: ";
        cin >> p2;
        cout << "The sum of the two polynomials is: " << p1 + p2 << endl;
        break;
      case 2:
        cout << "Enter the second polynomial: ";
        cin >> p2;
        cout << "The difference of the two polynomials is: " << p1 - p2 << endl;
        break;
      case 3:
        cout << "Enter the second polynomial: ";
        cin >> p2;
        cout << "The product of the two polynomials is: " << p1 * p2 << endl;
        break;
      case 4:
        cout << "Enter the constant: ";
        cin >> c;
        cout << "The sum of the polynomial and the constant is: " << p1 + c << endl;
        break;
      case 5:
        cout << "Enter the constant: ";
        cin >> c;
        cout << "The difference of the polynomial and the constant is: " << p1 - c << endl;
        break;
      case 6:
        cout << "Enter the constant: ";
        cin >> c;
        cout << "The product of the polynomial and the constant is: " << p1 * c << endl;
        break;
      case 7:
        cout << "The polynomial is: " << p1 << endl;
        break;
      case 8:
        p1.clean();
        cout << "The polynomial is: " << p1 << endl;
        break;
      case 9:
        break;
      case 10:
        double x;
        cout << "Enter the value of x: ";
        cin >> x;
        cout << "The value of the polynomial at x is: " << eval(p1,x) << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  }
  
  return 0;
}


