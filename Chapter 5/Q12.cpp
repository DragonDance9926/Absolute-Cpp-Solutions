#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;
#define width 80
#define height 22
#define iter 1000

bool boolisAliveorDead(int board[height][width] ,int i, int j){
    int alive_count = 0;
    int dead_count = 0;
    for(int di = -1 ; di <= 1;di++){
        for(int dj = -1; dj <= 1; dj++){
            if(di == 0 && dj == 0)
                continue;
            if(i+di < 0 || i+di >= height || j+dj < 0 || j+dj >= width)
                continue;
            if(board[i+di][j+dj] == 1)
                alive_count++;
            else
                dead_count++;
        }
    }
    if(board[i][j] == 1){
        if(alive_count < 2 || alive_count > 3)
            return false;
        else
            return true;
    }
    else{
        if(alive_count == 3)
            return true;
        else
            return false;
    }
}


void gameoflife(int board[height][width]){
    vector<tuple<int,int,bool>> buffer;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(boolisAliveorDead(board,i,j))
                buffer.push_back(make_tuple(i,j,true));
            else
                buffer.push_back(make_tuple(i,j,false));
        }
    }
    for(const auto&[i,j,b]:buffer){
        if(b)
            board[i][j] = 1;
        else
            board[i][j] = 0;
    }
}

void print_gol(int board[height][width]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << setw(2) << (board[i][j] ? "*" : " ");
        }
        cout << endl;
    }
}
bool boardempty(int board[height][width]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(board[i][j] == 1)
                return false;
        }
    }
    return true;
}
int main(){
    int gameoflifearr[height][width];
    fstream f;
    /*
    f.open("gameoflifeboard.txt",ios::out);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            f << '0' << ' ';
        }
        f << endl;
    }
    f.close();
    return 0;
    */
    f.open("gameoflifeboard.txt",ios::in);
    char c;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            f >> gameoflifearr[i][j];
        }
    }
    int turn = 0;
    //print_gol(gameoflifearr);
    //return 0;
    do{
        gameoflife(gameoflifearr);
        //print_gol(gameoflifearr);
        fstream file;
        file.open("gameoflife.txt", ios::out);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++)
                file << (gameoflifearr[i][j] ? "*" : " ");
            file << "\n";
        }
        file.close();
        //Wait for 1 second
        _sleep(250);
        turn++;
    }while (!boardempty(gameoflifearr) && turn < iter);
    
    
    return 0;
}