#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    vector<int> notes;
    int count[100] = {0};
    int note;
    do{
        cout << "Enter the note: ";
        cin >> note;
        if(note > 0){
            notes.push_back(note);
            count[note]++;
        }
    }while (note > 0);
    for(int i = 0; i < 100; i++){
        if(count[i] > 0){
            cout << i << ": " << setfill('*') << setw(count[i]) << "*" << endl;
        }
    }

    auto uniquenote = count_if(count, count + 100, [](int a) -> bool {return a > 0;});
    cout << "Unique notes: " << uniquenote << endl;
}