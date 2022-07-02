#include <iostream>
#include <vector>
#include <cstdlib>
#define NUMBER_FINALISTS 25
#define PRIZE_COUNT 4
using namespace std;

int main(){
    vector <bool> finalists(NUMBER_FINALISTS, false);
    for (int i = 0;i < PRIZE_COUNT ;){
        int winner = rand() % NUMBER_FINALISTS;
        if (!finalists[winner]){
            finalists[winner] = true;
            i++;
        }
    }
    for (int i = 0;i < NUMBER_FINALISTS;i++){
        if (finalists[i]){
            cout << "Finalist " << i+1 << endl;
        }
    }
    return 0;
}