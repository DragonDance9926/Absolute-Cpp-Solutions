#include <iostream>
using namespace std;

class two2d{
    private:
        int max_row, max_col;
        int** arr;
    public:
        two2d(int row, int col);
        two2d(const two2d& t);
        ~two2d();
        void set(int row, int col, int val);
        int get(int row, int col);
        two2d operator+(const two2d& t);
        two2d operator-(const two2d& t);
        two2d& operator=(const two2d& t);
        friend ostream& operator<<(ostream& os, const two2d& t);
        friend istream& operator>>(istream& is, two2d& t);
};

two2d::two2d(int row, int col){
    max_row = row;
    max_col = col;
    arr = new int*[max_row];
    for (int i = 0; i < max_row; i++){
        arr[i] = new int[max_col];
    }
}
two2d::two2d(const two2d& t){
    max_row = t.max_row;
    max_col = t.max_col;
    arr = new int*[max_row];
    for (int i = 0; i < max_row; i++){
        arr[i] = new int[max_col];
    }
    for (int i = 0; i < max_row; i++){
        for (int j = 0; j < max_col; j++){
            arr[i][j] = t.arr[i][j];
        }
    }
}
two2d::~two2d(){
    for (int i = 0; i < max_row; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
void two2d::set(int row, int col, int val){
    arr[row][col] = val;
}
int two2d::get(int row, int col){
    return arr[row][col];
}
two2d two2d::operator+(const two2d& t){
    two2d temp(max_row, max_col);
    for (int i = 0; i < max_row; i++){
        for (int j = 0; j < max_col; j++){
            temp.set(i, j, arr[i][j] + t.arr[i][j]);
        }
    }
    return temp;
}
two2d two2d::operator-(const two2d& t){
    two2d temp(max_row, max_col);
    for (int i = 0; i < max_row; i++){
        for (int j = 0; j < max_col; j++){
            temp.set(i, j, arr[i][j] - t.arr[i][j]);
        }
    }
    return temp;
}
two2d& two2d::operator=(const two2d& t){
    if (this == &t)
        return *this;
    for (int i = 0; i < max_row; i++){
        delete[] arr[i];
    }
    delete[] arr;
    max_row = t.max_row;
    max_col = t.max_col;
    arr = new int*[max_row];
    for (int i = 0; i < max_row; i++){
        arr[i] = new int[max_col];
    }
    for (int i = 0; i < max_row; i++){
        for (int j = 0; j < max_col; j++){
            arr[i][j] = t.arr[i][j];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const two2d& t){
    for (int i = 0; i < t.max_row; i++){
        for (int j = 0; j < t.max_col; j++){
            os << t.arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
istream& operator>>(istream& is, two2d& t){
    for (int i = 0; i < t.max_row; i++){
        for (int j = 0; j < t.max_col; j++){
            cout << "Enter value for row " << i << " col " << j << ": ";
            is >> t.arr[i][j];
        }
    }
    return is;
}
int main(){
    two2d t1(3, 3);
    two2d t2(3, 3);
    cout << "Enter values for t1: " << endl;
    cin >> t1;
    cout << "Enter values for t2: " << endl;
    cin >> t2;
    cout << "t1: " << endl;
    cout << t1 << endl;
    cout << "t2: " << endl;
    cout << t2 << endl;
    two2d t3 = t1 + t2;
    cout << "t1 + t2: " << endl;
    cout << t3 << endl;
    two2d t4 = t1 - t2;
    cout << "t1 - t2: " << endl;
    cout << t4 << endl;
    return 0;
}

