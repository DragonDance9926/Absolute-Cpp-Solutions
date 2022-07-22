#include <iostream>
#include "f.hpp"
#include "g.hpp"
using namespace std;

int main(){
    A::f();
    A::g();
    f();
    g();
    return 0;
}