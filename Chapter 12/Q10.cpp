#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
double calc_avg_word_len(istream& input){
    int word_count = 0;
    int total_len = 0;
    string word;
    while (input >> word){
        word_count++;
        total_len += word.length();
    }
    return static_cast<double>(total_len) / word_count;
}


double calc_avg_word_len(const string text){
    istringstream input(text);
    return calc_avg_word_len(input);
}

int main(){
    int choice;
    cout << "Enter 1 for file input, 2 for console input: ";
    cin >> choice;
    if (choice == 1){
        ifstream input("Q10.txt");
        if (!input){
            cout << "Error opening file" << endl;
            return 1;
        }
        cout << "Average word length: " << calc_avg_word_len(input) << endl;
    }
    else if (choice == 2){
        fflush(stdin);
        string text;
        cout << "Enter text: ";
        getline(cin, text);
        cout << "Average word length: " << calc_avg_word_len(text) << endl;
    }
    else{
        cout << "Invalid input" << endl;
    }
    return 0;
}