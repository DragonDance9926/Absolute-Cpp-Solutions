#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#define MOVIE_COUNT 6
#define PERSON 4
using namespace std;

void printarr(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printarr(double arr[][MOVIE_COUNT], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < MOVIE_COUNT; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

double nearestneightbor(double person[MOVIE_COUNT], double arr2[MOVIE_COUNT]){
    double res = 0;
    for (int i = 0;i < MOVIE_COUNT; i++){
        if (person[i] != -1){
            res += pow(person[i] - arr2[i], 2);
        }
    }
    return res;
}

bool menu(double arr[MOVIE_COUNT]){
    int rated = 0;
    int rate;
    while (rated < 3){
        cout << "Choose one of the following options: " << endl;
        for (int i = 0; i < MOVIE_COUNT; i++){
            cout << i+1 << ": Rate Movie " << 100+i << endl;
        }
        int choice;
        cin >> choice;
        if (choice > MOVIE_COUNT || choice < 1){
            cout << "Invalid choice" << endl;
            continue;
        }
        else{
            rate = choice - 1;
            cout << "Rate: ";
            if (arr[rate] == -1){
                cin >> arr[rate];
                rated++;
            }
            else{
                cout << "You have already rated this movie" << endl;
            }
        }
    }
    return true;
}

void fillestimaded(double arr[MOVIE_COUNT], double arr2[MOVIE_COUNT]){
    for (int i = 0; i < MOVIE_COUNT; i++){
        if (arr[i] == -1){
            arr[i] = arr2[i];
        }
    }
}

int main(){
    double movie[PERSON][MOVIE_COUNT] = {
        {3,1,5,2,1,5},
        {4,2,1,4,2,4},
        {3,1,2,4,4,1},
        {5,1,4,2,4,2}
    };
    double your_ratings[MOVIE_COUNT] = {-1,-1,-1,-1,-1,-1};
    menu(your_ratings);
    int min_index = 0;
    double min_distance = nearestneightbor(your_ratings, movie[0]);
    for (int i = 1; i < PERSON; i++){
        double distance = nearestneightbor(your_ratings, movie[i]);
        if (distance < min_distance){
            min_distance = distance;
            min_index = i;
        }
    }
    cout << "The nearest neighbor is: " << min_index + 1 << endl;
    fillestimaded(your_ratings, movie[min_index]);
    cout << "Your estimated ratings: " << endl;
    printarr(your_ratings, MOVIE_COUNT);
    return 0;
}
