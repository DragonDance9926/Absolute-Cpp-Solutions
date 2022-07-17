#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while (getline(cin, s)){
        if (s.length() == 0)
            break;
        for (int i = 0; i < s.length(); i++){
            s[i] = i == 0 ? toupper(s[i]) : tolower(s[i]);
        }
        cout << s << endl;
    }
    return 0;
}