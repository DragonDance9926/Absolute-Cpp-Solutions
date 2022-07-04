#include <iostream>
#include <cstdlib>

double converttomph(int minutes,int seconds){
    return 1/(minutes / 60.0 + seconds / 3600.0);
}
double convertomph(double kph){
    return kph * 0.621371;
}


int main(){
    std::cout << "1 - Enter the time in minutes and seconds per mile\n";
    std::cout << "2 - Enter the speed in kilometers per hour\n";
    std::cout << "3 - Exit\n";
    int choice;
    std::cin >> choice;
    while (choice != 3){
        switch (choice){
        case 1:
            int minutes,seconds;
            std::cout << "Enter the time in minutes and seconds per mile: ";
            std::cin >> minutes >> seconds;
            std::cout << "The speed in miles per hour is: " << converttomph(minutes,seconds) << "\n";
            break;
        case 2:
            double kph;
            std::cout << "Enter the speed in kilometers per hour: ";
            std::cin >> kph;
            std::cout << "The speed in miles per hour is: " << convertomph(kph) << "\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
        std::cout << "1 - Enter the time in minutes and seconds per mile\n";
        std::cout << "2 - Enter the speed in kilometers per hour\n";
        std::cout << "3 - Exit\n";
        std::cin >> choice;
    }
    return 0;
}
