#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void create_sorted(ofstream& outfile,int num){
    vector<int> v;
    for (int i = 0; i < num; i++){
        v.push_back(rand() % 10000);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < num; i++){
        outfile << v[i] << endl;
    }
}

void merge(ifstream& f1, ifstream& f2, ofstream& f3){
    int num1, num2;
    f1 >> num1;
    f2 >> num2;
    while (!f1.eof() && !f2.eof()){
        if (num1 < num2){
            f3 << num1 << endl;
            f1 >> num1;
        }
        else{
            f3 << num2 << endl;
            f2 >> num2;
        }
    }
    while (!f1.eof()){
        f3 << num1 << endl;
        f1 >> num1;
    }
    while (!f2.eof()){
        f3 << num2 << endl;
        f2 >> num2;
    }
}





int main(){
    /*
    ofstream file1, file2;
    file1.open("Q6-1.txt");
    file2.open("Q6-2.txt");
    if (file1.fail() || file2.fail()){
        cout << "Error opening file" << endl;
        return 1;
    }
    create_sorted(file1, 50);
    create_sorted(file2, 100);
    file1.close();
    file2.close();
    return 0;
    */
   ifstream file1, file2;
   ofstream file3;
    file1.open("Q6-1.txt");
    file2.open("Q6-2.txt");
    file3.open("Q6-3.txt");
    if (file1.fail() || file2.fail() || file3.fail()){
        cout << "Error opening file" << endl;
        return 1;
    }
    merge(file1, file2, file3);
    file1.close();
    file2.close();
    file3.close();
    return 0;
}