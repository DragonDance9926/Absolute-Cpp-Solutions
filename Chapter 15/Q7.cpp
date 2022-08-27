#include <iostream>
#include <cstdlib>
using namespace std;

class Dice{
    private:
        int sides;
    public:
        Dice(){
            sides = 6;
        }
        Dice(int s){
            sides = s;
        }
        int getSides(){
            return sides;
        }
        virtual int roll(){
            return rand() % sides + 1;
        }
        virtual int rollndiceatsametime(int n){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += roll();
            }
            return sum;
        }
};


class LoadedDice: public Dice{
    public:
        LoadedDice(): Dice(){};
        LoadedDice(int s): Dice(s){}
        virtual int roll(){
            int chance = rand() % 100;
            if(chance < 50){
                return getSides();
            }
            else{
                return Dice::roll();
            }
        }
        virtual int rollndiceatsametime(int n){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += roll();
            }
            return sum;
        }
};


int main(){
    srand(time(NULL));
    LoadedDice d;
    int v[7] = {0};
    for(int i = 0; i < 100; i++){
        v[d.roll()]++;
    }
    for(int i = 1; i <= d.getSides(); i++){
        cout << i << ": " << v[i] << endl;
    }
    return 0;
}