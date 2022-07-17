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
                if (buffer == "He" || buffer == "She"){
                    res += "He/She";
                }
                else if (buffer == "he" || buffer == "she"){
                    res += "he/she";
                }
                else if (buffer == "His" || buffer == "Her"){
                    res += "His/Her";
                }
                else if (buffer == "his" || buffer == "her"){
                    res += "his/her";
                }
                else if (buffer == "him" || buffer == "her"){
                    res += "him/her";
                }
                else if (buffer == "Him" || buffer == "Her"){
                    res += "Him/Her";
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