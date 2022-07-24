#include <iostream>
#include <string>
using namespace std;

void reverse(string& word,int l,int r){
    if (l < r){
        char temp = word[l];
        word[l] = word[r];
        word[r] = temp;
    }
    else{
        return;
    }
    reverse(word,l+1,r-1);
}

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;
    reverse(word, 0, word.length() - 1);
    cout << word << endl;
    return 0;
}