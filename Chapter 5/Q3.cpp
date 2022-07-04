#include <iostream>
#include <cmath>
using namespace std;

void input(double *arr,int size){
    for (int i = 0; i < size; i++){
        cout <<  "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

double avg(double *arr,int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}

double deriation(double *arr,int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += (arr[i] - avg(arr,size)) * (arr[i] - avg(arr,size));
    }
    return sqrt(sum / size);
}

int main(){
    cout << "Size of array: ";
    int size;
    cin >> size;
    double *arr = new double[size];
    input(arr,size);
    cout << "Average: " << avg(arr,size) << endl;
    cout << "Deriation: " << deriation(arr,size) << endl;
    delete[] arr;
    return 0;
}
