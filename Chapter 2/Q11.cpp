#include <iostream>
#include <string>
#include <fstream>
int main(){
    std::string first_name, last_name;
    int feet,inches;
    std::fstream input;
    input.open("Q11.txt");
    while (input >> first_name >> last_name >> feet >> inches){
        std::cout << first_name << " " << last_name << " " << feet << " " << inches << "\n";
    }
    input.close();
    return 0;
}