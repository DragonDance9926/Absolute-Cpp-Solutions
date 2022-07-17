#include <iostream>
#include <string>
using namespace std;

bool is_vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string pig_latin(const string text){
    string res;
    if (is_vowel(text[0])){
        res = text + "way";
    }
    else{
        res = text.substr(1) + text[0] + "ay";
    }
    return res;
}



int main(){
    string s;
    while (getline(cin, s)){
        if (s.length() == 0)
            break;
        cout << pig_latin(s) << endl;
    }
    return 0;
}