#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define PEOPLE 1000
using namespace std;

string createname(int);
void createfile(fstream&);
void returnmaxscore(fstream&, string, int&);

int main(){
    fstream file;
    createfile(file);
    int maxscore = 0;
    string name;
    returnmaxscore(file, name, maxscore);
    cout << "The highest score is " << maxscore << " by " << name << endl;
    return 0;
}

string createname(int i){
    //i = 1 -> A
    //i = 2 -> B
    //i = 3 -> C
    //i = 4 -> D
    //i = 26 -> Z
    //i = 27 -> AA
    string name;
    while (i > 0){
        int rem = i % 26;
        if (rem == 0){
            name += 'Z';
            i = i / 26 - 1;
        }
        else{
            name += char(rem + 'A' - 1);
            i = i / 26;
        }   
    }
    //reverse the string
    for (int i = 0; i < name.length() / 2; i++){
        char temp = name[i];
        name[i] = name[name.length() - i - 1];
        name[name.length() - i - 1] = temp;
    }
    return name;
}

void createfile(fstream& file){
    file.open("score.txt", ios::out);
    for (int i = 0; i < PEOPLE; i++){
        string name = createname(i+1);
        file << name << " " << rand() % 10000 << endl;
    }
    file.close();
}

void returnmaxscore(fstream& file, string name, int& max){
    file.open("score.txt", ios::in);
    string tempname;
    int tempscore;
    while (file >> tempname >> tempscore){
        if (tempscore > max){
            max = tempscore;
            name = tempname;
        }
    }
    file.close();
}