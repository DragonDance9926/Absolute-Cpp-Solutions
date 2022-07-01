#include <iostream>
using namespace std;
int main(){
    int Celcius,Fahrenheit;
    Celcius = 101;
    do{
        Celcius--;
        Fahrenheit = (Celcius * 9 / 5.0) + 32;
        cout << Celcius << "C is " << Fahrenheit << "F" << endl;
    }while (Celcius != Fahrenheit);
    return 0;
}