#include <iostream>
#include <iomanip>
#include <cstdlib>
#define SIZE 500
using namespace std;

void input(int[],int&);
void getmaxmin(int[],int,int&,int&);

int main(){
    srand(time(0));
    int arr[SIZE];
    int size;
    int max,min;
    input(arr,size);
    getmaxmin(arr,size,max,min);
    int *counter = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; i++){
        counter[i] = 0;
    }
    for (int i = 0; i < size; i++){
        counter[arr[i] - min]++;
    }
    cout << setw(10) << "Number" << setw(10) << "Frequency" << endl;
    for (int i = 0; i < max - min + 1; i++){
        if (counter[i] > 0){
            cout << setw(10) << i + min << setw(10) << counter[i] << endl;
        }
    }
    delete[] counter;
    return 0;
}

void input(int arr[],int &size){
    int lower = -15;
    int upper = 15;
    cout << "Size of array: ";
    cin >> size;
    for (int i = 0; i < size; i++){
        cout <<  "arr[" << i << "] = ";
        arr[i] = rand() % (upper - lower + 1) + lower;
        cout << arr[i] << "\n";
    }
}
void getmaxmin(int arr[],int size,int &max,int &min){
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }
}

