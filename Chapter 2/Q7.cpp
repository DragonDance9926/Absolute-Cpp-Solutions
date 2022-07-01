#include<iostream>
using namespace std;
int main(){
    int N;
    int currscore = 0;
    int maxscore = 0;
    int i = 0;
    cout << "Enter the number of test scores: ";
    cin >> N;
    for (i = 1;i <= N;i++){
        int temp;
        cout << "Score recieved on test " << i << ": ";
        cin >> temp;
        currscore += temp;
        cout << "Maximum score on test " << i << ": ";
        cin >> temp;
        maxscore += temp;
    }
    double percent = (double)currscore*100/maxscore;
    cout << "Your current score is " << currscore << " out of " << maxscore << " (" << percent << "%).\n";
    return 0;
}