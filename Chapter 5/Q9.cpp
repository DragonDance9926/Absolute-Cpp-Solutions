#include <iostream>
#include <cstdlib>
#include <cstdlib>
using namespace std;
void printtable(char **tictactoe){
    for(int i = 0; i < 3; i++){
        cout << "|";
        for(int j = 0; j < 3; j++){
            cout << tictactoe[i][j] << "|";
        }
        cout << endl;
    }
}


bool checkforwin(char **tictactoe,char player){
    for(int i = 0; i < 3; i++){
        if(tictactoe[i][0] == player && tictactoe[i][1] == player && tictactoe[i][2] == player){
            return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(tictactoe[0][i] == player && tictactoe[1][i] == player && tictactoe[2][i] == player){
            return true;
        }
    }
    if(tictactoe[0][0] == player && tictactoe[1][1] == player && tictactoe[2][2] == player){
        return true;
    }
    if(tictactoe[0][2] == player && tictactoe[1][1] == player && tictactoe[2][0] == player){
        return true;
    }
    return false;
}

bool checkforfull(char **tictactoe){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tictactoe[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}



void place(char **tictactoe, int row, int col, char player){
    if (tictactoe[row][col] == ' '){
        tictactoe[row][col] = player;
    }
    else{
        cout << "Invalid move" << endl;
    }
}

void turn(char **tictactoe, char player){
    int row, col;
    do {
        /*
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        row--;
        col--;
        */
       row = rand() % 3;
       col = rand() % 3;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || tictactoe[row][col] != ' ');
    place(tictactoe, row, col, player);
}

int main(){
    srand(time(NULL));
    char **tictactioe = new char*[3];
    for(int i = 0; i < 3; i++){
        tictactioe[i] = new char[3];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tictactioe[i][j] = ' ';
        }
    }
    bool Xwin = false;
    bool Owin = false;
    bool tie = false;
    while (!Xwin && !Owin && !tie){
        printtable(tictactioe);
        turn(tictactioe, 'X');
        Xwin = checkforwin(tictactioe, 'X');
        tie = checkforfull(tictactioe);
        if(!Xwin && !tie){
            printtable(tictactioe);
            turn(tictactioe, 'O');
            Owin = checkforwin(tictactioe, 'O');
            tie = checkforfull(tictactioe);
        }
    }
    printtable(tictactioe);
    if(Xwin){
        cout << "X wins" << endl;
    }
    else if(Owin){
        cout << "O wins" << endl;
    }
    else{
        cout << "Tie" << endl;
    }
    for(int i = 0; i < 3; i++){
        delete[] tictactioe[i];
    }
    delete[] tictactioe;
    return 0;
}