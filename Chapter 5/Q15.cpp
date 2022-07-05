#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void fillarr(char arr[10]){
    for(int i = 0; i < 10; i++){
        arr[i] = (rand() % 3) + '1';
    }
}

bool checkpin(char arr[10],string password,string check){
    //length of string
    if (check.length() != password.length()){
        return false;
    }
    for(int i = 0; i < check.length();i++){
        int index = password[i] - '0';
        if (arr[index] != check[i]){
            return false;
        }
    }
    return true;
}



int main(){
    srand(time(NULL));
    string password = "45245";
    char pinshuffle[10];
    fillarr(pinshuffle);
    for (int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++){
        cout << pinshuffle[i] << " ";
    }
    cout << endl;
    string check;
    cout << "Enter your pin: ";
    cin >> check;
    if (checkpin(pinshuffle,password,check)){
        cout << "Correct pin" << endl;
    }
    else{
        cout << "Incorrect pin" << endl;
    }
}