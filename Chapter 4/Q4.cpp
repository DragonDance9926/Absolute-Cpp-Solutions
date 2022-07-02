#include <iostream>

void input(int&,int&);
void convert(int,int,int&,int&);
void output(int,int);

int main(){
    int feet,inches;
    int meters,centimeters;
    bool running = true;
    while (running){
        input(feet,inches);
        convert(feet,inches,meters,centimeters);
        output(meters,centimeters);
        std::cout << "Do you want to continue? (y/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n'){
            running = false;
        }
    }
    return 0;
}

void input(int& feet,int& inches){
    std::cout << "Enter the height in feet and inches: \n";
    std::cin >> feet >> inches;
}
void convert(int feet,int inches,int& meters,int& centimeters){
    double totalInches = feet*12 + inches;
    //Convert inches to centimeters
    centimeters = totalInches*2.54;
    //Convert inches to meters
    meters = centimeters/100;
    centimeters -= meters*100;
}
void output(int meters,int centimeters){
    std::cout << "The height in meters and centimeters is " << meters << "." << centimeters << std::endl;
}
