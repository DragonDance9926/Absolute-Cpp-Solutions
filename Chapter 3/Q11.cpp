#include <iostream>
#include <cstdlib>
using namespace std;

void human_turn (int&);
void computer_turn (int&);

int main(){
    srand(time(NULL));
    int human_score = 0;
    int computer_score = 0;
    while (human_score < 100 && computer_score < 100){
        cout << "Human score: " << human_score << endl;
        cout << "Computer score: " << computer_score << endl;
        human_turn(human_score);
        computer_turn(computer_score);
    }
    if (human_score > computer_score){
        cout << "Human wins!" << endl;
    }
    else if (human_score < computer_score){
        cout << "Computer wins!" << endl;
    }
    else{
        cout << "It's a tie!" << endl;
    }
    return 0;
}

void human_turn(int& point){
    int sum_of_points = 0;
    char choice;
    bool turnover = false;
    do{
        int dice = rand() % 6 + 1;
        cout << "You rolled a " << dice << endl;
        switch (dice){
            case 1:
                cout << "You lost your turn" << endl;
                turnover = true;
                break;
            default:
                cout << "You rolled a " << dice << endl;
                sum_of_points += dice;
                cout << "Your total is " << sum_of_points << endl;
                cout << "(r)oll again or (h)old: ";
                cin >> choice;
                if (choice == 'r'){
                    cout << "You choose to roll again" << endl;
                    turnover = false;
                }
                else if (choice == 'h'){
                    cout << "You choose to hold" << endl;
                    point += sum_of_points;
                    cout << "Your point is " << point << endl;
                    turnover = true;
                }
                else{
                    cout << "Invalid inputs are accepted as 'r'" << endl;
                    turnover = false;
                }
                break;
        }
    }while(!turnover);
}

void computer_turn(int& point){
    int sum_of_points = 0;
    char choice;
    bool turnover = false;
    do{
        int dice = rand() % 6 + 1;
        cout << "Computer rolled a " << dice << endl;
        switch (dice){
            case 1:
                cout << "It lost its turn" << endl;
                turnover = true;
                break;
            default:
                sum_of_points += dice;
                choice = (sum_of_points >= 20) ? 'h' : 'r';
                if (choice == 'r'){
                    cout << "Computer chooses to roll again" << endl;
                    turnover = false;
                }
                else if (choice == 'h'){
                    cout << "Computer chooses to hold" << endl;
                    point += sum_of_points;
                    cout << "Computer's point is " << point << endl;
                    turnover = true;
                }
                else{
                    cout << "Invalid inputs are accepted as roll over" << endl;
                    turnover = false;
                }
                break;
        }
    }while(!turnover);
}



