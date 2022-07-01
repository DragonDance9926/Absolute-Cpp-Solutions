#include <iostream>

const double G = 6.673e-8;

double gravitycalculator(double m1, double m2, double r){
    return G * m1 * m2 / (r * r);
}

int main(){
    double m1,m2,d;
    bool running;
    do{
        std::cout << "Mass 1(gram): ";
        std::cin >> m1;
        std::cout << "Mass 2(gram): ";
        std::cin >> m2;
        std::cout << "Distance(cm): ";
        std::cin >> d;
        std::cout << "Gravity Force: " << gravitycalculator(m1,m2,d) << "\n";
    }while(running);
    return 0;
}