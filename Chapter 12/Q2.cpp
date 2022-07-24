#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void createdoublefile(ofstream& outfile, int num){
    int i;
    for (i = 0; i < num; i++)
    {
        outfile << (rand() % 10000 + 1) / 100.0 << endl;
    }
}

double avarage(ifstream& infile){
    double sum = 0;
    int count = 0;
    double temp;
    infile >> temp;
    sum += temp;
    count++;
    while(infile >> temp){
        sum += temp;
        count++;
    }
    return sum / count;
}

int main(){
    ifstream infile;
    ofstream outfile;
    int choice;
    cout << "1- Create a random double file" << endl;
    cout << "2- Find the average of a file" << endl;
    cout << "3- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(choice != 3){
        switch(choice){
            case 1:
                cout << "Enter the number of doubles: ";
                int num;
                cin >> num;
                outfile.open("Q2.txt");
                if (!outfile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                createdoublefile(outfile, num);
                outfile.close();
                cout << "File created successfully" << endl;
                break;
            case 2:
                infile.open("Q2.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                cout << "The average of the file is: " << avarage(infile) << endl;
                break;
        }
        cout << "1- Create a random double file" << endl;
        cout << "2- Find the average of a file" << endl;
        cout << "3- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}