#include <iostream>
#include "two2d.hpp"
using namespace std;
using namespace t2d;

int main(){
    Two2D t1;
    cin >> t1;
    cout << t1 << endl;
    Two2D t2(t1);
    cout << t2 << endl;
    Two2D t3 = t1 + t2;
    cout << t3 << endl;
    Two2D t4 = t1 - t2;
    cout << t4 << endl;
    return 0;
}