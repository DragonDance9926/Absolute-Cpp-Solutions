#include <iostream>
#include <iomanip>
int main(){
    double guess;
    double r;
    int iter;
    double n;
    std::cout << "Square root of: ";
    std::cin >> n;
    guess = n / 2;
    std::cout << "Iteration: ";
    std::cin >> iter;
    for (int i = 0; i < iter; i++){
        r = n / guess;
        guess = (guess + r) / 2;
        std::cout << std::setprecision(10) << "Iteration " << i << ": " << guess << "\n";
    }
    std::cout << "Square root of " << n << " is " << std::setprecision(10) << guess << "\n";
    return 0;
}