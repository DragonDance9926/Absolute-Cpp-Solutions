#include <iostream>
using namespace std;

void towerofhanoi(int n, char from, char to, char aux){
    if (n == 0){
        return;
    }
    else{
        towerofhanoi(n - 1, from, aux, to);
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        towerofhanoi(n - 1, aux, to, from);
    }
}

int main(){
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}