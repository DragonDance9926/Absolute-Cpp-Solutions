#include <iostream>
#include <cstdlib>

int gcd(int a,int b){
    if (b == 0)
        return a;
    return gcd(b,a%b);
}

void convertToLowestTerms(int &a,int &b){
    int g = gcd(a,b);
    a /= g;
    b /= g;
}

int main(){
    int numerator,denominator;
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter the denominator:";
    std::cin >> denominator;
    std::cout << "The fraction is: " << numerator << "/" << denominator << "\n";
    convertToLowestTerms(numerator,denominator);
    std::cout << "The fraction in lowest terms is: " << numerator << "/" << denominator << "\n";
    return 0;
}