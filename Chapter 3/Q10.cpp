#include <iostream>

double male_child(double,double);
double female_child(double,double);

int main(){
    double mother,father,male,female;
    std::cout << "Mother height in inches: ";
    std::cin >> mother;
    std::cout << "Father height in inches: ";
    std::cin >> father;
    male = male_child(mother,father);
    female = female_child(mother,father);
    std::cout << "Male child height: " << male << std::endl;
    std::cout << "Female child height: " << female << std::endl;
    return 0;
}

double male_child(double mother,double father){
    return ((mother * 13.0 / 12.0) + father) / 2.0;
}
double female_child(double mother,double father){
    return ((father * 12.0 / 13.0) + mother) / 2.0;
}
