#include<iostream>
using namespace std;
int main(){
    int capacity;
    int people;
    cout << "Maximum room capacity" << endl;
    cin >> capacity;
    cout << "Number of people" << endl;
    cin >> people;
    if(people <= capacity){
        cout << "Room is available";
        int remaining = capacity - people;
        cout << "Remaining capacity is " << remaining;
    }
    else{
        cout << "Room is not available" << endl;
        int remaining = people - capacity;
        cout << "Number of people who cannot fit in the room is " << remaining << endl;
    }
    return 0;
}