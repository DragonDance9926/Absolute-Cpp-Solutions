#include <iostream>
typedef struct sizes{
    double hat_size;
    double jacket_size;
    double waist_size;
}sizes;

sizes get_sizes(double height_inches, double weight_pounds, int age){
    sizes res = {0, 0, 0};
    res.hat_size = weight_pounds/ height_inches * 2.9;
    res.jacket_size = ((height_inches * weight_pounds) / 288) + (0.125 * ((age - 30) / 10));
    res.waist_size = (weight_pounds / 5.7) + (0.1 * ((age - 28) / 2));
    return res;
}


int main(){
    double height_inches,weight_pounds;
    int age;
    bool running = true;
    do{
        std::cout << "Enter your height in inches: ";
        std::cin >> height_inches;
        std::cout << "Enter your weight in pounds: ";
        std::cin >> weight_pounds;
        std::cout << "Enter your age: ";
        std::cin >> age;
        sizes res = get_sizes(height_inches, weight_pounds, age);
        std::cout << "Hat size: " << res.hat_size << "\n";
        std::cout << "Jacket size: " << res.jacket_size << "\n";
        std::cout << "Waist size: " << res.waist_size << "\n";
        std::cout << "Would you like to run again? (y/n): ";
        char c;
        std::cin >> c;
        switch(c){
            case 'y':
                running = true;
                break;
            case 'n':
                running = false;
                break;
            default:
                std::cout << "Invalid input\n";
                running = false;
                break;
        }
    }while(running);
    return 0;
}