#include <iostream>
#include <cstdlib>
#define GAME 10000
using namespace std;

void setdoors(bool& door1, bool& door2, bool& door3);
int choosenontruedoor(bool door1, bool door2, bool door3,int choice);
bool checkdoors(bool door1, bool door2, bool door3,int choice);
bool human(bool door1, bool door2, bool door3);
bool computer(bool door1, bool door2, bool door3,bool switchornot);

int main(){
    srand(time(NULL));
    bool door1, door2, door3;
    int choice;
    /*
    Human:
    setdoors(door1, door2, door3);
    cout << door1 << door2 << door3 << endl;
    human(door1, door2, door3);
    */
   int win = 0;
   int lose = 0;
   for(int i = 0; i < GAME; i++){
       setdoors(door1, door2, door3);
       if (computer(door1, door2, door3,false)){
           win++;
       }
       else{
           lose++;
       }
   }
    cout << "Win percentage: " << (double)win/GAME*100 << "%" << endl;
    cout << "Lose percentage: " << (double)lose/GAME*100 << "%" << endl;
}

void setdoors(bool& door1, bool& door2, bool& door3){
    int winner = rand() % 3 + 1;
    switch (winner){
        case 1:
            door1 = true;
            door2 = false;
            door3 = false;
            break;
        case 2:
            door1 = false;
            door2 = true;
            door3 = false;
            break;
        case 3:
            door1 = false;
            door2 = false;
            door3 = true;
            break;
    }
}

int choosenontruedoor(bool door1, bool door2, bool door3,int choice){
    int res;
    bool running = true;
    do{
        res = rand() % 3 + 1;
        if (res != choice){
            switch (res){
                case 1:
                    if (door1 == false){
                        running = false;
                    }
                    break;
                case 2:
                    if (door2 == false){
                        running = false;
                    }
                    break;
                case 3:
                    if (door3 == false){
                        running = false;
                    }
                    break;
            }
        }
    }while(running);
    return res;
}

bool checkdoors(bool door1, bool door2, bool door3,int choice){
    bool result = false;
    switch (choice){
        case 1:
            if (door1 == true){
                result = true;
            }
            break;
        case 2:
            if (door2 == true){
                result = true;
            }
            break;
        case 3:
            if (door3 == true){
                result = true;
            }
            break;
    }
    return result;
}

bool human(bool door1, bool door2, bool door3){
    cout << "Choose Door 1 Door 2 or Door3: ";
    int guess;
    cin >> guess;
    cout << "One of the false doors is Door " << choosenontruedoor(door1, door2, door3,guess) << endl;
    cout << "Do you want to switch doors? (y/n) ";
    char answer;
    cin >> answer;
    if (answer == 'y'){
        cout << "Choose another door: ";
        cin >> guess;
    }
    if (checkdoors(door1, door2, door3,guess) == true){
        cout << "You won!" << endl;
        return true;
    }
    else{
        cout << "You lost!" << endl;
        return false;
    }
}

bool computer(bool door1, bool door2, bool door3,bool switchornot){
    int guess = rand() % 3 + 1;
    if (switchornot == true){
        int nonwindoor = choosenontruedoor(door1, door2, door3,guess);
        int newguess = 6-nonwindoor-guess;
        return checkdoors(door1, door2, door3,newguess);
    }
    else{
        return checkdoors(door1, door2, door3,guess);
    }
}