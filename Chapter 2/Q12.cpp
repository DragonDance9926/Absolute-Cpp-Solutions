#include <iostream>
#include <string>
#include <fstream>
#include <random>
#define RANDOM_NUMBER_LIMIT 10000
#define BIGGEST_NUMBER 1000
using namespace std;

int main(){
    //Create random numbers and write into a file
    fstream file;
    //Open file for writing
    file.open("Q12.txt", ios::out);
    //Set random number generator
    srand(time(NULL));
    //Generate random numbers and write them into the file
    for(int i = 0; i < RANDOM_NUMBER_LIMIT  ;i++){
        int random_number = (rand() % (BIGGEST_NUMBER - 1)) + 1;
        file << random_number << "\n";
    }
    //Close file
    file.close();
    int occur_of_1 = 0;
    int occur_of_2 = 0;
    int occur_of_3 = 0;
    int occur_of_4 = 0;
    int occur_of_5 = 0;
    int occur_of_6 = 0;
    int occur_of_7 = 0;
    int occur_of_8 = 0;
    int occur_of_9 = 0;
    //Open file for reading
    file.open("Q12.txt", ios::in);
    //Read numbers from the file and count the occurances of each number
    string buffer;
    while(file >> buffer){
        int number = buffer[0] - '0';
        switch (number){
            case 1:
                occur_of_1++;
                break;
            case 2:
                occur_of_2++;
                break;
            case 3:
                occur_of_3++;
                break;
            case 4:
                occur_of_4++;
                break;
            case 5:
                occur_of_5++;
                break;
            case 6:
                occur_of_6++;
                break;
            case 7:
                occur_of_7++;
                break;
            case 8:
                occur_of_8++;
                break;
            case 9:
                occur_of_9++;
                break;
            default:
                cout << "Reading error" << "\n";
                return 1;
        }
    }
    //Close file
    file.close();
    //Print the occurances of each number
    cout << "1: " << (static_cast<double>(occur_of_1) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "2: " << (static_cast<double>(occur_of_2) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "3: " << (static_cast<double>(occur_of_3) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "4: " << (static_cast<double>(occur_of_4) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "5: " << (static_cast<double>(occur_of_5) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "6: " << (static_cast<double>(occur_of_6) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "7: " << (static_cast<double>(occur_of_7) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "8: " << (static_cast<double>(occur_of_8) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    cout << "9: " << (static_cast<double>(occur_of_9) / RANDOM_NUMBER_LIMIT) * 100 << "\n";
    return 0;
}