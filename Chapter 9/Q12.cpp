#include <iostream>
using namespace std;

int stoi(const char* s){
    int n = 0;
    while (*s != '\0'){
        n = n * 10 + (*s - '0');
        s++;
    }
    return n;
}
int main(){
    char s1[100];
    while (cin >> s1){
        if (s1[0] == 'q')
            break;
        cout << stoi(s1) << endl;
    }
    return 0;
}