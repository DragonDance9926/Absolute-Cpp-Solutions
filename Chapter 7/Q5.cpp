#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Size of vector: ";
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    int dead = 2;
    while (v.size() > 1){
        v.erase(v.begin() + dead);
        dead = (dead + 2) % v.size();
        for (int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    cout << "The last one is " << v[0] << endl;
    return 0;
}