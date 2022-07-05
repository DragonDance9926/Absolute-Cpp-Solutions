#include <iostream>
#include <fstream>
#include <cstdlib>
#define NUM_LIMIT 10000
using namespace std;

void createfile(fstream&);
void count(fstream&, int[]);
void printarr(int[], int);
int main(){
    srand(time(NULL));
    fstream file;
    //createfile(file);
    int counter[10] = {0};
    count(file, counter);
    printarr(counter, 10);
    return 0;
}

void createfile(fstream& file){
    if (!file){
        cout << "File not found" << endl;
        return;
    }
    file.open("scores.txt", ios::out);
    for (int i = 0; i < NUM_LIMIT; i++){
        file << rand() << "\n";
    }
    file.close();
}

void count(fstream& file, int counter[]){
    file.open("scores.txt", ios::in);
    if (!file){
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(file, line)){
        counter[line[0] - '0']++;
    }
    file.close();
}

void printarr(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << i << ": " << (static_cast<double>(arr[i]) / NUM_LIMIT)*100 << endl;
    }
}