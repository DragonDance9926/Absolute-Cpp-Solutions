#include <iostream>

void sort(int &n1,int &n2,int &n3){
    if (n1 > n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if (n2 > n3){
        int temp = n2;
        n2 = n3;
        n3 = temp;
    }
    if (n1 > n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
}

int main(){
    int n1,n2,n3;
    std::cout << "Enter the first number: ";
    std::cin >> n1;
    std::cout << "Enter the second number: ";
    std::cin >> n2;
    std::cout << "Enter the third number: ";
    std::cin >> n3;
    sort(n1,n2,n3);
    std::cout << "The sorted numbers are: " << n1 << " " << n2 << " " << n3 << "\n";
    return 0;
}