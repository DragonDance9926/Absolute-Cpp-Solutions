#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SEAT_COL 4
#define SEAT_ROW 7
using namespace std;

void initilize_seats(char Seats[][SEAT_COL]){
    for(int i = 0; i < SEAT_ROW; i++){
        for(int j = 0; j < SEAT_COL; j++){
            switch (j){
                case 0:
                    Seats[i][j] = 'A';
                    break;
                case 1:
                    Seats[i][j] = 'B';
                    break;
                case 2:
                    Seats[i][j] = 'C';
                    break;
                case 3:
                    Seats[i][j] = 'D';
                    break;
                default:
                    break;
            }
        }
    }
}

void print_seats(char Seats[][SEAT_COL]){
    for(int i = 0; i < SEAT_ROW; i++){
        cout << setw(2) << i << "|";
        for(int j = 0; j < SEAT_COL; j++){
            cout << setw(2) << Seats[i][j] << "|";
        }
        cout << endl;
    }
}

int main(){
    char Seats[SEAT_ROW][SEAT_COL];
    initilize_seats(Seats);
    string seat_number;
    do{
        print_seats(Seats);
        cout << "Enter a seat number(type quit to exit): ";
        cin >> seat_number;
        if (seat_number == "quit"){
            break;
        }
        int row = seat_number[0] - '0';
        int col = seat_number[1] - 'A';
        if(row >= 0 && row < SEAT_ROW && col >= 0 && col < SEAT_COL && Seats[row][col] != 'X'){
            Seats[row][col] = 'X';
        }
        else if (row >= 0 && row < SEAT_ROW && col >= 0 && col < SEAT_COL && Seats[row][col] == 'X'){
            cout << "Seat already taken" << endl;
        }
        else{
            cout << "Invalid seat number" << endl;
        }
    }while(true);

}