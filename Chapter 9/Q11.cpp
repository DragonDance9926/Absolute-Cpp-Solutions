#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

bool isannagram(string s1,string s2){
    vector <int> count(26, 0);
    vector <int> count2(26, 0);
    for (int i = 0; i < s1.size(); i++){
        char c = tolower(s1[i]);
        if (c >= 'a' && c <= 'z')
            count[c - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++){
        char c = tolower(s2[i]);
        if (c >= 'a' && c <= 'z')
            count2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (count[i] != count2[i])
            return false;
    }
    return true;
}
int main(){
    string s1, s2;
    while (getline(cin,s1) && getline(cin,s2)){
        if (s1 == "q" && s2 == "q")
            break;
        if (isannagram(s1, s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}