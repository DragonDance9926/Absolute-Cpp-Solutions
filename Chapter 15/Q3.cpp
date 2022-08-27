#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#define SIZE 20
#define ANT_SIZE 100
#define DOODLEBUG_SIZE 5
using namespace std;


enum state {ANT = 'A', EMPTY = '.', DOODLEBUG = 'D'};

class Organism{
    private:
        char symbol;
    public:
        Organism(){
            symbol = EMPTY;
        }
        virtual char getSymbol(){
            return symbol;
        }
        virtual char setSymbol(char s){
            symbol = s;
            return symbol;
        }
        virtual void move(vector<vector<Organism*>>& board, int i, int j){
            // do nothing
        }
        virtual void breed(vector<vector<Organism*>>& board, int i, int j){
            // do nothing
        }
        virtual ~Organism(){
            // do nothing
        }
};
class Ant: public Organism{
    private:
        int day_survived;
    public:
        vector<pair<int, int>> moves = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        Ant(): Organism(){
            setSymbol(ANT);
            day_survived = 0;
        }
        Ant(int day): Organism(){
            setSymbol(ANT);
            day_survived = day;
        }
        virtual void move(vector<vector<Organism*>>& board, int i, int j){;
            int empty = 0;
            for (auto m : moves){
                int newRow = i + m.first;
                int newCol = j + m.second;
                if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                    if (board[newRow][newCol]->getSymbol() == EMPTY){
                        empty++;
                    }
                }
            }
            if (empty > 0){
                bool moved = false;
                while (!moved){
                    int r = rand() % 4;
                    auto move = moves[r];
                    int newRow = i + move.first;
                    int newCol = j + move.second;
                    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                        if (board[newRow][newCol]->getSymbol() == EMPTY){
                            //cout << "Ant moved from " << i << "," << j << " to " << newRow << "," << newCol << endl;
                            board[newRow][newCol] = new Ant(day_survived + 1);
                            board[i][j] = new Organism();
                            //Breed
                            board[newRow][newCol]->breed(board, newRow, newCol);
                            moved = true;
                        }
                    }
                }
            }
            //call breed
        }
        virtual void breed(vector<vector<Organism*>>& board, int i, int j){
            if (day_survived > 3){
                int empty = 0;
                for (auto m : moves){
                    int newRow = i + m.first;
                    int newCol = j + m.second;
                    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                        if (board[newRow][newCol]->getSymbol() == EMPTY){
                            empty++;
                        }
                    }
                }
                if (empty > 0){
                    bool moved = false;
                    while (!moved){
                        int r = rand() % 4;
                        auto move = moves[r];
                        int newRow = i + move.first;
                        int newCol = j + move.second;
                        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                            if (board[newRow][newCol]->getSymbol() == EMPTY){
                                //cout << "New Ant created at " << newRow << "," << newCol << endl;
                                board[newRow][newCol] = new Ant();
                                moved = true;
                            }
                        }
                    }
                    day_survived = 0;
                }
                
            }
        }
};

class DoodleBug: public Organism{
    private:
        int day_survived;
        int days_since_ate;
    public:
        vector<pair<int, int>> moves = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        DoodleBug(): Organism(){
            setSymbol(DOODLEBUG);
            day_survived = 0;
            days_since_ate = 0;
        }
        DoodleBug(int day, int ate): Organism(){
            setSymbol(DOODLEBUG);
            day_survived = day;
            days_since_ate = ate;
        }
        virtual void move(vector<vector<Organism*>>& board, int i, int j){
            int empty = 0;
            bool moved = false;
            for (auto m : moves){
                int newRow = i + m.first;
                int newCol = j + m.second;
                if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                    if (board[newRow][newCol]->getSymbol() == EMPTY){
                        empty++;
                    }
                    else if (board[newRow][newCol]->getSymbol() == ANT){
                        //cout << "Doodlebug ate an ant at " << newRow << "," << newCol << endl;
                        board[newRow][newCol] = new DoodleBug(day_survived + 1, 0);
                        board[i][j] = new Organism();
                        moved = true;
                    }
                }
            }
            if (!moved && empty > 0){
                while (!moved){
                    int r = rand() % 4;
                    auto move = moves[r];
                    int newRow = i + move.first;
                    int newCol = j + move.second;
                    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                        if (board[newRow][newCol]->getSymbol() == EMPTY){
                            if (days_since_ate < 2){
                                //cout << "Doodlebug moved from " << i << "," << j << " to " << newRow << "," << newCol << endl;
                                board[newRow][newCol] = new DoodleBug(day_survived + 1, days_since_ate + 1);
                                board[i][j] = new Organism();
                                //Breed
                                board[newRow][newCol]->breed(board, newRow, newCol);
                                moved = true;
                            }
                            else{
                                //cout << "Doodlebug starved at " << newRow << "," << newCol << endl;
                                board[newRow][newCol] = new Organism();
                                board[i][j] = new Organism();
                                moved = true;
                            }
                            moved = true;
                        }
                    }
                }
            }
            //call breed
        }
        virtual void breed(vector<vector<Organism*>>& board, int i, int j){
            if (day_survived >= 8){
                int empty = 0;
                for (auto m : moves){
                    int newRow = i + m.first;
                    int newCol = j + m.second;
                    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                        if (board[newRow][newCol]->getSymbol() == EMPTY){
                            empty++;
                        }
                    }
                }
                if (empty > 0){
                    bool moved = false;
                    while (!moved){
                        int r = rand() % 4;
                        auto move = moves[r];
                        int newRow = i + move.first;
                        int newCol = j + move.second;
                        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE){
                            if (board[newRow][newCol]->getSymbol() == EMPTY){
                                //cout << "New Doodlebug created at " << newRow << "," << newCol << endl;
                                board[newRow][newCol] = new DoodleBug();
                                moved = true;
                            }
                        }
                    }
                    day_survived = 0;
                }
                
            }
        }
};




void print(vector<vector<Organism*>>& board){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << board[i][j]->getSymbol();
        }
        cout << endl;
    }
}


int main(){
    srand(time(NULL));
    vector<vector<Organism*>> board(SIZE, vector<Organism*>(SIZE, new Organism()));
    Ant ant;
    for(int curr_ant = 0; curr_ant < ANT_SIZE;){
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (board[i][j]->getSymbol() == EMPTY){
            board[i][j] = &ant;
            curr_ant++;
        }
    }
    DoodleBug doodlebug;
    for(int curr_doodlebug = 0; curr_doodlebug < DOODLEBUG_SIZE;){
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (board[i][j]->getSymbol() == EMPTY){
            board[i][j] = &doodlebug;
            curr_doodlebug++;
        }
    }
    char _;
    int generation = 30;
    for(int gen = 0; gen < generation; gen++){
        int ant_count = 0;
        int doodlebug_count = 0;
        system("clear");
        cout << "Generation " << gen << endl;
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                if (board[i][j]->getSymbol() == ANT){
                    ant_count++;
                }
                else if (board[i][j]->getSymbol() == DOODLEBUG){
                    doodlebug_count++;
                }
            }
        }
        cout << "Ants: " << ant_count << endl;
        cout << "Doodlebugs: " << doodlebug_count << endl;
        print(board);
        vector<pair<int, int>> poses;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if (board[i][j]->getSymbol() == ANT || board[i][j]->getSymbol() == DOODLEBUG){
                    poses.push_back(make_pair(i, j));
                }
            }
        }
        for(auto pos : poses){
            board[pos.first][pos.second]->move(board, pos.first, pos.second);
        }
        cin >> _;
        cout << endl;
    }
    return 0;
}