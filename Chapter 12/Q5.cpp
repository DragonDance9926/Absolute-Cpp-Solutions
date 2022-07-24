#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void take_advice(ifstream& infile){
    if (infile.eof()){
        return;
    }
    cout << "Here is the advice you requested:" << endl;
    char ch;
    while (infile.get(ch)){
        cout << ch;
    }
    cout << endl;
}

void print_advice(ofstream& outfile){
    if (outfile.fail()){
        return;
    }
    cout << "Enter your advice: ";
    string advice;
    do{
        getline(cin, advice);
        outfile << advice << endl;
    } while (advice.length() != 0);
}

int main(){
    ofstream outfile;
    ifstream infile;
    infile.open("Q5.txt");
    take_advice(infile);
    infile.close();
    outfile.open("Q5.txt");
    print_advice(outfile);
    outfile.close();
    return 0;
}