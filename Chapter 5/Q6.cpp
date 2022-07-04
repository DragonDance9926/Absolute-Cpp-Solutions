#include <iostream>
#include <cstdlib>
#define SIZE 7
using namespace std;
typedef struct diver{
    double difficulty;
    double final_score;
    double scores[SIZE];
}Diver;

int create_Random(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

double calculate_Final_Score(Diver d){
    double min,max;
    double sum = 0;
    min = max = d.scores[0];
    for (int i = 0; i < SIZE; i++){
        if (d.scores[i] < min){
            min = d.scores[i];
        }
        if (d.scores[i] > max){
            max = d.scores[i];
        }
        sum += d.scores[i];
    }
    sum -= min + max;
    sum *= d.difficulty;
    return sum*0.6;
}


Diver create_Diver(){
    Diver d;
    d.difficulty = create_Random(12,36) / 10.0;
    for (int i = 0; i < SIZE; i++){
        d.scores[i] = create_Random(1,100) / 10.0;
    }
    d.final_score = calculate_Final_Score(d);
    return d;
}

void print_Diver(Diver d){
    cout << "Difficulty: " << d.difficulty << endl;
    cout << "Scores: ";
    for (int i = 0; i < SIZE; i++){
        cout << d.scores[i] << " ";
    }
    cout << endl;
    cout << "Final Score: " << d.final_score << endl;
}



int main(){
    Diver d;
    char choice;
    do{
        d = create_Diver();
        print_Diver(d);
        cout << "Continue? (y/n): ";
        cin >> choice;
    }while (choice == 'y');
    return 0;
}
