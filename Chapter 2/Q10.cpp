#include<iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    string buffer;
    fstream input;
    input.open("Q10.txt");
    while (input >> buffer){
        cout << (buffer.compare("hate") == 0 ? "love":buffer) << " ";
    }
    input.close();
    return 0;
}
