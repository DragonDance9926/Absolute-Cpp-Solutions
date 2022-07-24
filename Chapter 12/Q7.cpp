#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string parseletter(ifstream& in){
    string res,buffer;
    while (in >> buffer){
        res += buffer;
        res += " ";
    }
    return res;
}


string fill (string letter,string name){
    stringstream ss(letter);
    string res;
    string word;
    while (ss >> word){
        res += word == "#N#" ? name : word;
        res += " ";
    }
    return res;
}




int main(){
    ifstream file1;
    file1.open("Q7.txt");
    if (!file1.is_open()){
        cout << "File not found" << endl;
        return 1;
    }
    string res = parseletter(file1);
    file1.close();
    cout << res << endl;
    cout << fill(res,"John") << endl;
    return 0;
}