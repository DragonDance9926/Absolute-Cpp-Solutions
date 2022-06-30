#include <iostream>
using namespace std;
int main(){
    int seconds;
    cout << "Enter time in seconds" << endl;
    cin >> seconds;
    int hours = seconds / 3600;
    seconds = seconds % 3600;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    return 0;
}