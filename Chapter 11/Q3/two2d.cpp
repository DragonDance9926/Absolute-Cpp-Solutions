#include <iostream>
#include "two2d.hpp"
using std::cout;
using std::endl;

namespace t2d{
    Two2D::Two2D(){
        max_row = 0;
        max_col = 0;
        arr = NULL;
    }
    Two2D::Two2D(int row, int col){
        max_row = row;
        max_col = col;
        arr = new int*[max_row];
        for(int i = 0; i < max_row; i++){
            arr[i] = new int[max_col];
        }
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                arr[i][j] = 0;
            }
        }
    }

    Two2D::Two2D(const Two2D& t){
        max_row = t.max_row;
        max_col = t.max_col;
        arr = new int*[max_row];
        for(int i = 0; i < max_row; i++){
            arr[i] = new int[max_col];
        }
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                arr[i][j] = t.arr[i][j];
            }
        }
    }
    Two2D::~Two2D(){
        for (int i = 0; i < max_row; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }
    int Two2D::get(int row, int col) const{
        if (row < 0 || row >= max_row || col < 0 || col >= max_col){
            cout << "Error: out of range" << endl;
            return 0;
        }
        return arr[row][col];
    }
    int Two2D::get_max_row() const{
        return max_row;
    }
    int Two2D::get_max_col() const{
        return max_col;
    }
    void Two2D::set(int row, int col, int val){
        if (row < max_row && col < max_col){
            arr[row][col] = val;
        }
        else{
            cout << "Error: out of range" << endl;
        }
    }
    Two2D Two2D::operator+(const Two2D& t){
        if (max_row != t.max_row || max_col != t.max_col){
            cout << "Error: incompatible dimensions" << endl;
            return *this;
        }
        Two2D temp(max_row, max_col);
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                temp.arr[i][j] = arr[i][j] + t.arr[i][j];
            }
        }
        return temp;
    }
    Two2D Two2D::operator-(const Two2D& t){
        if (max_row != t.max_row || max_col != t.max_col){
            cout << "Error: incompatible dimensions" << endl;
            return *this;
        }
        Two2D temp(max_row, max_col);
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                temp.arr[i][j] = arr[i][j] - t.arr[i][j];
            }
        }
        return temp;
    }
    Two2D& Two2D::operator=(const Two2D& t){
        if (max_row != t.max_row || max_col != t.max_col){
            cout << "Error: incompatible dimensions" << endl;
            return *this;
        }
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                arr[i][j] = t.arr[i][j];
            }
        }
        return *this;
    }


    std::ostream& operator<<(std::ostream& os, const Two2D& t){
        for(int i = 0; i < t.max_row; i++){
            for(int j = 0; j < t.max_col; j++){
                os << t.arr[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Two2D& t){
        cout << "Enter the number of rows: ";
        is >> t.max_row;
        cout << "Enter the number of columns: ";
        is >> t.max_col;
        t.arr = new int*[t.max_row];
        for(int i = 0; i < t.max_row; i++){
            t.arr[i] = new int[t.max_col];
        }
        for(int i = 0; i < t.max_row; i++){
            for(int j = 0; j < t.max_col; j++){
                cout << "Enter value for row " << i << " col " << j << ": ";
                is >> t.arr[i][j];
            }
        }
        return is;
    }
}


