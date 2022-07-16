#include <iostream>
#include <cmath>
using namespace std;

class Vector{
    private:
        double x;
        double y;
        double getx();
        double gety();
    public:
        Vector(double x = 0,double y = 0);
        friend ostream &operator<<(ostream &os,const Vector &c);
        friend istream &operator>>(istream &is,Vector &c);
        Vector operator+(Vector c);
        Vector operator-(Vector c);
        Vector operator*(Vector c);
};

Vector::Vector(double x,double y){
    this->x = x;
    this->y = y;
}
double Vector::getx(){
    return x;
}
double Vector::gety(){
    return y;
}
ostream &operator<<(ostream &os,const Vector &c){
    os << "(" << c.x << "," << c.y << ")";
    return os;
}
istream &operator>>(istream &is,Vector &c){
    is >> c.x >> c.y;
    return is;
}
Vector Vector::operator+(Vector c){
    return Vector(x + c.x,y + c.y);
}
Vector Vector::operator-(Vector c){
    return Vector(x - c.x,y - c.y);
}
Vector Vector::operator*(Vector c){
    return Vector(x * c.x,y * c.y);
}
int main(){
    Vector v1,v2;
    cin >> v1 >> v2;
    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << v1 * v2 << endl;
    return 0;
}