#include <iostream>
#include <string>
using namespace std;

void reverse(string& word){
    if (word.length() == 0){
        return;
    }
    else{
        for (int i = 0; i < word.length() / 2; i++){
            char temp = word[i];
            word[i] = word[word.length() - 1 - i];
            word[word.length() - 1 - i] = temp;
        }
    }
}

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;
    reverse(word);
    cout << word << endl;
    return 0;
}