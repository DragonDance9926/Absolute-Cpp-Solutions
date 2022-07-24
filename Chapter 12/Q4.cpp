#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void create_file(ostream& outfile,int num){
    for (int i = 0; i < num; i++)
    {
        outfile << rand() % 1000 + 1 << endl;
    }
}

double avarage(ifstream& infile){
    double sum = 0;
    int count = 0;
    double temp;
    while(infile >> temp){
        sum += temp;
        count++;
    }
    return sum / count;
}
double derivation(ifstream& infile,double avg){
    double sum = 0;
    int count = 0;
    double temp;
    while(infile >> temp){
        sum += (temp - avg) * (temp - avg);
        count++;
    }
    return sqrt(sum / count);
}

int main(){
    ifstream infile;
    ofstream outfile;
    int choice;
    double avg;
    do{
        cout << "1- Create a random integer file" << endl;
        cout << "2- Find the average value in a file" << endl;
        cout << "3- Find the derivation of the average value in a file" << endl;
        cout << "4- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the number of integers: ";
                int num;
                cin >> num;
                outfile.open("Q4.txt");
                if (!outfile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                create_file(outfile, num);
                outfile.close();
                cout << "File created successfully" << endl;
                break;
            case 2:
                infile.open("Q4.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                cout << "The average value is: " << avarage(infile) << endl;
                infile.close();
                break;
            case 3:
                infile.open("Q4.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                avg = avarage(infile);
                infile.close();
                infile.open("Q4.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                cout << "The derivation of the average value is: " << derivation(infile,avg) << endl;
                infile.close();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }while (choice != 4);
    return 0;
    
}

