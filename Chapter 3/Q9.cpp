#include <iostream>
#include <cstdlib>
#define GAME_LENGTH 13345
using namespace std;

bool game(){
    bool gameover = false;
    bool win = false;
    while (!gameover){
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int sum = die1 + die2;
        switch (sum){
            case 7:
            case 11:
                win = true;
                gameover = true;
                break;
            case 2:
            case 3:
            case 12:
                gameover = true;
                break;
            default:
                while (!gameover){
                    die1 = rand() % 6 + 1;
                    die2 = rand() % 6 + 1;
                    sum = die1 + die2;
                    switch (sum){
                        case 7:
                            gameover = true;
                            break;
                        case 4:
                        case 5:
                        case 6:
                        case 8:
                        case 9:
                        case 10:
                            win = true;
                            break;
                        default:
                            break;
                    }
                }
                break;
        }
    }
    return win;
}


int main(){
    srand(time(NULL));
    int wincount = 0;
    int losecount = 0;
    for (int i = 0; i < GAME_LENGTH; i++){
        if (game()){
            wincount++;
        }
        else{
            losecount++;
        }
    }
    double winrate = (static_cast<double>(wincount) / GAME_LENGTH)*100;
    cout << "Win rate: " << winrate << endl;
    return 0;
}