#include <iostream>
#include <cstring>
using namespace std;

bool isequal(const char* s1, const char* s2){
    char c1, c2;
    while (*s1 != '\0' && *s2 != '\0'){
        while (*s1 != '\0' && *s1 == ' ' && *s1 == ',')
            s1++;
        while (*s2 != '\0' && *s2 == ' ' && *s2 == ',')
            s2++;
        c1 = tolower(*s1);
        c2 = tolower(*s2);
        if (c1 == c2){
            s1++;
            s2++;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char s1[100], s2[100];
    while (cin >> s1 >> s2){
        if (strlen(s1) == 1 && s1[0] == 'q')
            break;
        if (isequal(s1, s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}