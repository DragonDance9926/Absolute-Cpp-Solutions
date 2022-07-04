#include <iostream>


int difftime(int start,int end){
    return end - start;
}

int main(){
    int start,end;
    std::cout << "Enter the start time: ";
    std::cin >> start;
    std::cout << "Enter the end time: ";
    std::cin >> end;
    std::cout << "The time difference is: " << difftime(start,end) << "\n";
    return 0;
}