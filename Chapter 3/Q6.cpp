#include <iostream>
#include <cmath>
#define N 5

double standarddeviation(const double arr[]){
    double res = 0,mean = 0;
    for(int i = 0; i < N; i++){
        mean += arr[i];
    }
    mean /= N;
    for(int i = 0; i < N; i++){
        res += pow(arr[i] - mean, 2);
    }
    res /= N;
    return sqrt(res);
}

int main(){
    double arr[N];
    bool running = true;
    do{
        std::cout << "Enter numbers: ";
        for(int i = 0; i < N; i++){
            std::cout << "Number " << i + 1 << ": ";
            std::cin >> arr[i];
        }
        std::cout << "The standard deviation is: " << standarddeviation(arr) << "\n";
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