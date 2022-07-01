#include <iostream>
using namespace std;

int main(){
    double amonuttokillmouse;
    double mouseweight;
    double dieterweight;
    double stopweight;
    cout << "Enter the amount of artificial sweetener needed to kill a mouse: ";
    cin >> amonuttokillmouse;
    cout << "Enter the weight of the mouse: ";
    cin >> mouseweight;
    cout << "Enter the weight of the dieter: ";
    cin >> dieterweight;
    cout << "Enter the weight of the stop: ";
    cin >> stopweight;
    if (stopweight >=dieterweight){
        cout << "The stop is heavier than the dieter." << endl;
    }
    double max_sweetener = amonuttokillmouse * dieterweight / mouseweight;
    cout << "\nIt is possible to drink " << max_sweetener << " soda without dying.";
    return 0;
}