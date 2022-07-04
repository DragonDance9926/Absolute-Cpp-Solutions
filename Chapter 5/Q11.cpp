#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#define SIZE 6
using namespace std;
int histogram_max(int array[]){
    int max = array[0];
    for(int i = 1; i < SIZE; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

vector<vector<char>> histo(int histogram[SIZE]){
    int max = histogram_max(histogram);
    vector<vector<char>> histo_array;
    for(int i = 0; i < SIZE; i++){
        vector<char> row;
        for(int j = 0; j < max;j++){
            if (j < histogram[i]){
                row.push_back('*');
            }
            else{
                row.push_back(' ');
            }
        }
        histo_array.push_back(row);
    }
    return histo_array;
}

vector<vector<char>> transpose(vector<vector<char>> histo_array){
    vector<vector<char>> transposed_histo_array;
    int col_size = histo_array[0].size();
    int row_size = histo_array.size();
    for(int i = 0; i < col_size; i++){
        vector<char> row;
        for(int j = 0; j < row_size; j++){
            row.push_back(histo_array[j][i]);
        }
        transposed_histo_array.push_back(row);

    }
    return transposed_histo_array;
}

void reversecols(vector<vector<char>> &histo_array){
    int col_size = histo_array[0].size();
    int row_size = histo_array.size();
    for(int i = 0; i < col_size; i++){
        for(int j = 0; j < row_size/2; j++){
            char temp = histo_array[j][i];
            histo_array[j][i] = histo_array[row_size-j-1][i];
            histo_array[row_size-j-1][i] = temp;
        }
    }
}


int main(){
    int histogram[SIZE] = {2,2,4,5,10,4};
    //Print the histogram vertically
    vector<vector<char>> histo_array = histo(histogram);
    for(int i = 0; i < histo_array.size(); i++){
        for(int j = 0; j < histo_array[i].size(); j++){
            cout << histo_array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<char>> transposed_histo_array = transpose(histo_array);
    reversecols(transposed_histo_array);
    for(int i = 0; i < transposed_histo_array.size(); i++){
        for(int j = 0; j < transposed_histo_array[i].size(); j++){
            cout << transposed_histo_array[i][j];
        }
        cout << endl;
    }
}
