#include <iostream>
#include <cstdlib>
#include <iomanip>
void shufflematrix(int **matrix,int n){
    //shuffle the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = matrix[i][j];
            int r = rand() % n;
            matrix[i][j] = matrix[r][j];
            matrix[r][j] = temp;
        }
    }
}

void creatematrix(int **matrix,int n){
    //create the matrix
    int s = 1;
    int s_count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = s;
            s_count++;
            if(s_count == 2){
                s++;
                s_count = 0;
            }
        }
    }
}

void printmatrix(int **matrix,int n,int ci = -1,int cj = -1,int c2i = -1,int c2j = -1){
    //print the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (ci != -1 && cj != -1 && ci == i && cj == j){
                std::cout << std::setw(3) << matrix[i][j];
            }
            else if(c2i != -1 && c2j != -1 && c2i == i && c2j == j){
                std::cout << std::setw(3) << matrix[i][j];
            }
            else if(matrix[i][j] == -1){
                std::cout << std::setw(3) << matrix[i][j];
            }
            else{
                std::cout << std::setw(3) << "*";
            }
        }
        std::cout << std::endl;
    }
}
void inputgame(int **matrix,int n,int& row,int& col){
    //input the game
    bool valid = false;
    /*
    while (!valid){
        std::cout << "Enter the row and column of the number you want to flip: ";
        std::cin >> row >> col;
        if(row >= 0 && row < n && col >= 0 && col < n){
            if (matrix[row][col] == -1){
                std::cout << "This number is already flipped!" << std::endl;
            }
            else{
                valid = true;
            }
        }
        else{
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
    */
   do{
    row = rand() % n;
    col = rand() % n;
    }while(matrix[row][col] == -1);
}

int main(){
    srand(time(NULL));
    int row1,row2,col1,col2;
    int n = 4;
    int **matrix = new int*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new int[n];
    }
    std::cout << std::endl;
    creatematrix(matrix,n);
    shufflematrix(matrix,n);
    int pairs = (n*n)/2;
    while (pairs > 0){
        printmatrix(matrix,n);
        std::cout << std::endl;
        inputgame(matrix,n,row1,col1);
        printmatrix(matrix,n,row1,col1);
        inputgame(matrix,n,row2,col2);
        printmatrix(matrix,n,row1,col1,row2,col2);
        if (row1 == row2 && col1 == col2){
            std::cout << "You filpped the same number!" << std::endl;
        }
        else if (matrix[row1][col1] == matrix[row2][col2]){
            matrix[row1][col1] = -1;
            matrix[row2][col2] = -1;
            pairs--;
        }
        else{
            std::cout << "The numbers are not the same!" << std::endl;
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}