#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


void createrandomintfile(ofstream& outfile, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        outfile << rand() % 1000 + 1 << endl;
    }
}

void findmaxmin(ifstream& infile, int *max, int *min){
    int temp;
    infile >> temp;
    *max = temp;
    *min = temp;
    while(infile >> temp){
        if(temp > *max){
            *max = temp;
        }
        if(temp < *min){
            *min = temp;
        }
    }
}


int main(){
    ifstream infile;
    ofstream outfile;
    int choice, max, min;
    cout << "1- Create a random integer file" << endl;
    cout << "2- Find the maximum and minimum values in a file" << endl;
    cout << "3- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(choice != 3){
        switch(choice){
            case 1:
                cout << "Enter the number of integers: ";
                int num;
                cin >> num;
                outfile.open("Q1.txt");
                if (!outfile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                createrandomintfile(outfile, num);
                outfile.close();
                cout << "File created successfully" << endl;
                break;
            case 2:
                infile.open("Q1.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                findmaxmin(infile, &max, &min);
                cout << "Maximum value: " << max << endl;
                cout << "Minimum value: " << min << endl;
                infile.close();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << "1- Create a random integer file" << endl;
        cout << "2- Find the maximum and minimum values in a file" << endl;
        cout << "3- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}