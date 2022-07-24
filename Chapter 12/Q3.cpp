#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void create_file(ostream& outfile, vector<int>& v){
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        outfile << v[i] << endl;
    }
}

int find_median(ifstream& infile){
    vector<int> temp;
    int temp2;
    while(infile >> temp2){
        temp.push_back(temp2);
    }
    if(temp.size() % 2 == 0){
        return (temp[temp.size() / 2] + temp[temp.size() / 2 - 1]) / 2;
    }
    else{
        return temp[temp.size() / 2];
    }
}

int main(){
    ifstream infile;
    ofstream outfile;
    vector<int> v;
    int choice;
    cout << "1- Create a random integer file" << endl;
    cout << "2- Find the median value in a file" << endl;
    cout << "3- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(choice != 3){
        switch(choice){
            case 1:
                cout << "Enter the number of integers: ";
                int num;
                cin >> num;
                for(int i = 0; i < num; i++){
                    v.push_back(rand() % 1000 + 1);
                }
                outfile.open("Q3.txt");
                if (!outfile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                create_file(outfile, v);
                outfile.close();
                cout << "File created successfully" << endl;
                break;
            case 2:
                infile.open("Q3.txt");
                if (!infile)
                {
                    cout << "Error opening file" << endl;
                    exit(1);
                }
                cout << "The median value of the file is: " << find_median(infile) << endl;
                infile.close();
                break;
        }
        cout << "1- Create a random integer file" << endl;
        cout << "2- Find the median value in a file" << endl;
        cout << "3- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}