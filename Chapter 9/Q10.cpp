#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    vector <string> questions(5);
    vector <string> choices(5);
    vector <int> answers(5);
    questions[0] = "Biggest city in the world?\n";
    questions[1] = "Biggest country in the world?\n";
    questions[2] = "Biggest river in the world?\n";
    questions[3] = "Biggest mountain in the world?\n";
    questions[4] = "Biggest ocean in the world?\n";
    choices[0] = "1-Istanbul\n2-Tokyo\n3-Beijing\n4-Moscow\n";
    choices[1] = "1-China\n2-Russia\n3-United States\n4-United Kingdom\n";
    choices[2] = "1-Amazon\n2-Nile\n3-Mississippi\n4-Yangtze\n";
    choices[3] = "1-Mount Everest\n2-K2\n3-Kangchenjunga\n4-Makalu\n";
    choices[4] = "1-Pacific\n2-Atlantic\n3-Indian\n4-Arctic\n";
    answers[0] = 2;
    answers[1] = 2;
    answers[2] = 1;
    answers[3] = 1;
    answers[4] = 1;
    const int points = 10;
    int score = 0;
    for (int i = 0; i < 5; i++){
        cout << questions[i];
        cout << choices[i];
        int answer;
        cin >> answer;
        if (answer == answers[i]){
            score += points;
        }
        else{
            cout << "Wrong!" << "Correct answer is " << answers[i] << endl;
        }
    }
    cout << "Your score is " << score << endl;
    return 0;
}