#include <iostream>
using namespace std;

class Myint{
    private:
        int value;
    public:
        Myint(int value = 0);
        int operator[](int index);
};

Myint::Myint(int value){
    this->value = value;
}
int Myint::operator[](int index){
    //find the value at index
    int i = 0;
    int temp = value;
    while(i < index){
        temp = temp / 10;
        if (temp == 0)
            return -1;
        i++;
    }
    temp = temp % 10;
    return temp;
}

int main(){
    Myint m(12345);
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;
    cout << m[4] << endl;
    cout << m[5] << endl;
    return 0;
}