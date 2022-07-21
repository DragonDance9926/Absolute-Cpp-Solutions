#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Histogram{
    private:
        int maxvalue;
        int* grades;
    public:
        Histogram(int, vector<int>);
        ~Histogram();
        friend ostream& operator<<(ostream&, const Histogram&);
};

Histogram::Histogram(int max, vector<int> input){
   maxvalue = max;
    grades = new int[maxvalue + 1];
    for (int i = 0; i < maxvalue + 1; i++){
        grades[i] = 0;
    }
    for (int i = 0; i < input.size(); i++){
        grades[input[i]]++;
    }
}
Histogram::~Histogram(){
    delete[] grades;
}
ostream& operator<<(ostream& out, const Histogram& h){
    for (int i = 0; i <= h.maxvalue; i++){
        if (h.grades[i] != 0){
            out << i << ": ";
            for (int j = 0; j < h.grades[i]; j++){
                out << "*";
            }
            out << endl;
        }
    }
    return out;
}
int main(){
    vector<int> grades;
    int max;
    cout << "Enter maximum value: ";
    cin >> max;
    cout << "Enter grades: ";
    int grade;
    do{
        cin >> grade;
        grades.push_back(grade);
    }while(grade != -1);
    Histogram h(max, grades);
    cout << h;
    return 0;
}