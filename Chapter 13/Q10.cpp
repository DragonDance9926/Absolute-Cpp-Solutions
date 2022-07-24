#include <iostream>
#include <string>
using namespace std;


void pyramid_iter(int n){
    for (int i = 0;i < n ;i++){
        for (int space = n - i; space > 0; space--){
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++){
            cout << "*";
            cout << " ";
        }
        cout << endl;
    }
}
void pyramid_recur(int index,int n){
    if (index == n){
        return;
    }
    else{
        for (int space = n - index; space > 0; space--){
            cout << " ";
        }
        for (int j = 0; j < index + 1; j++){
            cout << "*";
            cout << " ";
        }
        cout << endl;
        pyramid_recur(index + 1, n);
    }
}

int main(){
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    pyramid_iter(n);
    pyramid_recur(0, n);
    return 0;
}