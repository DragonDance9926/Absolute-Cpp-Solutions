#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Player{
    private:
        string name;
        int score;
    public:
        Player(string name, int score){
            this->name = name;
            this->score = score;
        }
        void print(){
            cout << "Name: " << name << endl;
            cout << "Score: " << score << endl;
        }
        void find_max_score(fstream &file){
            file.open("score.txt",ios::in);
            string name;
            int score;
            file >> name >> score;
            while (file >> name >> score){
                if (score > this->score){
                    this->name = name;
                    this->score = score;
                }
            }
            file.close();
        }
};



int main(){
    fstream file;
    Player player("",0);
    player.find_max_score(file);
    player.print();
    return 0;
}