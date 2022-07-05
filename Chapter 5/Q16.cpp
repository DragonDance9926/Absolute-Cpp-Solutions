#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>
#define MOVIE_COUNT 6
#define PERSON 1000
using namespace std;

void createfile(fstream &file){
    if (!file){
        cout << "File not found" << endl;
        return;
    }
    file.open("ratings.txt", ios::out);
    for (int i = 0; i < PERSON; i++){
        for (int j = 0; j < MOVIE_COUNT; j++){
            file << (rand() % 100) / 10.0 << " ";
        }
        file << endl;
    }
    file.close();
}

bool menu(double arr[MOVIE_COUNT]){
    int rated = 0;
    int rate;
    while (rated < 3){
        cout << "Choose one of the following options: " << endl;
        for (int i = 0; i < MOVIE_COUNT; i++){
            cout << i+1 << ": Rate Movie " << 100+i << (arr[i] != -1 ? " Already Rated":" Not Rated") << endl;
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


double nearestneightbor(double person[MOVIE_COUNT], double arr2[MOVIE_COUNT]){
    double res = 0;
    for (int i = 0;i < MOVIE_COUNT; i++){
        if (person[i] != -1){
            res += pow(person[i] - arr2[i], 2);
        }
    }
    return res;
}

void fillestimaded(double arr[MOVIE_COUNT], double arr2[MOVIE_COUNT]){
    for (int i = 0; i < MOVIE_COUNT; i++){
        if (arr[i] == -1){
            arr[i] = arr2[i];
        }
    }
}

int main(){
    srand(time(NULL));
    fstream file;
    createfile(file);
    double your_ratings[MOVIE_COUNT];
    for (int i = 0; i < MOVIE_COUNT; i++){
        your_ratings[i] = -1;
    }
    menu(your_ratings);
    double buffer[MOVIE_COUNT];
    int min_index = 0;
    double min_distance;
    double local_distance;
    file.open("ratings.txt", ios::in);
    for(int i = 0; i < PERSON; i++){
        for (int j = 0; j < MOVIE_COUNT; j++){
            file >> buffer[j];
        }
        if (i != 0){
            local_distance = nearestneightbor(your_ratings, buffer);
            if (local_distance < min_distance){
                min_distance = local_distance;
                min_index = i;
            }
        }
        else{
            min_distance = nearestneightbor(your_ratings, buffer);
            min_index = i;
        }
    }
    cout << "The nearest neighbor is " << min_index +1 << endl;
    file.close();
    fillestimaded(your_ratings, buffer);
    cout << "Your ratings: " << endl;
    for (int i = 0; i < MOVIE_COUNT; i++){
        cout << "Movie " << 100+i << ": " << your_ratings[i] << endl;
    }
    return 0;
}