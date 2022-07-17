#include <iostream>
#include <string>
using namespace std;

string edit (const string text){
    string res;
    string buffer = "";
    int index = 0;
    char i;
    for (int c = 0; c < text.length(); c++){
        if (text[c] != ' ' && text[c] != ',' && text[c] != '.' && text[c] != '!' && text[c] != '?'){
            buffer += text[c];
        }
        else{
            if (buffer.length() > 0){
                if (buffer.length() == 4){
                    res += index == 0 ? "Love":"love";
                }
                else{
                    res += buffer;
                }
                buffer = "";
            }
            res += text[c];
            index++;
        }
    }
    return res;
}




int main(){
    string text;
    cout << "Enter a string: ";
    getline(cin,text);
    cout << "Result: " << edit(text) << endl;
    return 0;
}