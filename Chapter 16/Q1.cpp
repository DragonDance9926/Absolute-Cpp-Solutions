#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
bool isSorted(vector<T>& v){
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

template<class T>

int binarysearch(vector<T>& v, T key){
    if (v.size() == 0){
        cout << "Empty vector" << endl;
        return -1;
    }
    if (!isSorted(v)){
        cout << "Vector is not sorted" << endl;
        return -1;
    }
    int low = 0;
    int high = v.size() - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (v[mid] == key){
            return mid;
        }
        else if (v[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> v;
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    for (int i = 0; i < size; i++){
        int x;
        cout << "Enter element " << i << ": ";
        cin >> x;
        v.push_back(x);
    }
    int key;
    cout << "Enter the key: ";
    cin >> key;
    int index = binarysearch(v, key);
    if (index == -1){
        cout << "Key not found" << endl;
    }
    else{
        cout << "Key found at index " << index << endl;
    }
    vector<char> vc;
    int size1;
    cout << "Enter the size of the vector: ";
    cin >> size1;
    for (int i = 0; i < size1; i++){
        char x;
        cout << "Enter element " << i << ": ";
        cin >> x;
        vc.push_back(x);
    }
    char key1;
    cout << "Enter the key: ";
    cin >> key1;
    int index1 = binarysearch(vc, key1);
    if (index1 == -1){
        cout << "Key not found" << endl;
    }
    else{
        cout << "Key found at index " << index1 << endl;
    }
    return 0;
}