#include <iostream>
#include <string>
using namespace std;

template <class T>

T abs_val(T n1, T n2){
    if (n1 > n2)
        return n1 - n2;
    else
        return n2 - n1;
}

int main(){
    cout << abs_val(1, 2) << endl;
    cout << abs_val(2, 1) << endl;
    cout << static_cast<int>(abs_val('a', 'b')) << endl;
    cout << static_cast<int>(abs_val('c', 'a')) << endl;
    cout << abs_val(9.2, 2.5) << endl;
    cout << abs_val(2.521314, 9.23435) << endl;
    return 0;
}