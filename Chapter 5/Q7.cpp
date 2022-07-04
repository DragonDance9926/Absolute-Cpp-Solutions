#include <iostream>
#include <cstdlib>
#define SIZE 6
using namespace std;
void input(int *arr,int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand()%SIZE;
    }
}

void fillpoints(int counter[SIZE] , int *arr, int size){
    for (int i = 0; i < size; i++){
        counter[arr[i]]++;
    }
}

void print_histogram(int counter[SIZE]){
    for (int i = 0; i < SIZE; i++){
        cout << i << ": ";
        for (int j = 0; j < counter[i]; j++){
            cout << "*";
        }
        cout << endl;
    }
}
int main(){
    int size;
    int points[SIZE];
    for (int i = 0; i < SIZE; i++){
        points[i] = 0;
    }
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array = new int[size];
    input(array,size);
    fillpoints(points,array,size);
    print_histogram(points);
    delete[] array;
}