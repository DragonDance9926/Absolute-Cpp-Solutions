#include <iostream>
#include<string>

using namespace std;

void input(char *arr,int size){
    for (int i = 0; i < size; i++){
        cout <<  "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void delete_repeats(char *arr,int &size){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] == arr[j]){
                for (int k = j; k < size - 1; k++){
                    arr[k] = arr[k + 1];
                }
                size--;
            }
        }
    }
}

int main(){
    cout << "Size of array: ";
    int size;
    cin >> size;
    char *arr = new char[size];
    input(arr,size);
    delete_repeats(arr,size);
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}