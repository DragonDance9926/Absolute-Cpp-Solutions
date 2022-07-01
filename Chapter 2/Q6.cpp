#include <iostream>
using namespace std;
int main(){
    double buoyantforce;
    double volume;
    double weight;
    double radius;
    cout << "Radius(feet): ";
    cin >> radius;
    cout << "Weight(pounds): ";
    cin >> weight;
    volume = (4.0/3.0)*3.14159*radius*radius*radius;
    buoyantforce = volume*62.4;
    if (buoyantforce >= weight){
        cout << "The object will float.\n";
    }
    else{
        cout << "The object will sink.\n";
    }
}