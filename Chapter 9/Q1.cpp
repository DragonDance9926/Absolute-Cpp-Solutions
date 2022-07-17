#include <iostream>
#include <string>
using namespace std;
string editedstring(const string text){
    string res;
    bool spaceused = false;
    for(int i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            if(!spaceused){
                res += ' ';
                spaceused = true;
            }
        }
        else{
            res += i == 0 ? toupper(text[i]) : tolower(text[i]);
            spaceused = false;
        }
    }
    return res;
}


int main(){
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Edited string: " << editedstring(input) << endl;
    return 0;
}