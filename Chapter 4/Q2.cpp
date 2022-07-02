#include <iostream>
#include <cmath>
using namespace std;

bool triangle(double,double,double,double&,double&);
bool iftriangle(double,double,double);
int main(){
    double a,b,c,s1,s2;
    cout << "Enter the three sides of the triangle: \n";
    cin >> a >> b >> c;
    if(!triangle(a,b,c,s1,s2)){
        cout << "The sides do not form a triangle.\n";
    }
    else{
        cout << "The sides form a triangle.\n";
        cout << "The area of the triangle is " << s1 << " and the perimeter is " << s2 << endl;
    }
    return 0;
}

bool triangle(double l1,double l2,double l3,double& area,double& perimeter){
    if (iftriangle(l1,l2,l3)){
        double s = (l1+l2+l3)/2;
        area = sqrt(s*(s-l1)*(s-l2)*(s-l3));
        perimeter = l1+l2+l3;
        return true;
    }
    else{
        return false;
    }
}

bool iftriangle(double l1,double l2,double l3){
    if (l1+l2>l3 && l1+l3>l2 && l2+l3>l1){
        return true;
    }
    else{
        return false;
    }
}