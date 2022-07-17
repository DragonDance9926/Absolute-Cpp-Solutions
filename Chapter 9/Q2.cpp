#include <iostream>
#include <string>
using namespace std;
void counter(int arr[26], const string text){
    for(int i = 0; i < text.size(); i++){
        if(text[i] >= 'a' && text[i] <= 'z'){
            arr[text[i] - 'a']++;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z'){
            arr[text[i] - 'A']++;
        }
    }
}

int main(){
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int arr[26] = {0};
    counter(arr, input);
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) {
            cout << char(i + 'a') << ": " << arr[i] << endl;
        }
    }
    return 0;
}