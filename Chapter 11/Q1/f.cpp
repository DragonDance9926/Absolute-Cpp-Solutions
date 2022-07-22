#include <iostream>
#include "f.hpp"
using std::cout;
using std::endl;

namespace A{
    void f(){
        cout << "Function f in namespace A" << endl;
    }
}
void f(){
    cout << "Function f" << endl;
}