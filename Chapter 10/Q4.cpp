#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int numClasses;
        string* classes;
    public:
        Student();
        Student(const Student&);
        friend ostream& operator<<(ostream&, const Student&);
        friend istream& operator>>(istream&, Student&);
        Student& operator=(const Student&);
        void reset();
        ~Student();
};


Student::Student(){
    name = "";
    numClasses = 0;
    classes = NULL;
}

Student::Student(const Student& s){
    name = s.name;
    numClasses = s.numClasses;
    classes = new string[numClasses];
    for (int i = 0; i < numClasses; i++){
        classes[i] = s.classes[i];
    }
}

ostream& operator<<(ostream& out, const Student& s){
    out << "Name: " << s.name << endl;
    out << "Number of classes: " << s.numClasses << endl;
    out << "Classes: ";
    for (int i = 0; i < s.numClasses; i++){
        out << s.classes[i] << " ";
    }
    out << endl;
    return out;
}
istream& operator>>(istream& in, Student& s){
    cout << "Enter name: ";
    in >> s.name;
    cout << "Enter number of classes: ";
    in >> s.numClasses;
    s.classes = new string[s.numClasses];
    for (int i = 0; i < s.numClasses; i++){
        cout << "Enter class " << i + 1 << ": ";
        in >> s.classes[i];
    }
    return in;
}
void Student::reset(){
    name = "";
    numClasses = 0;
    delete[] classes;
    classes = NULL;
}

Student::~Student(){
    delete[] classes;
}

Student& Student::operator=(const Student& s){
    if (this != &s){
        name = s.name;
        numClasses = s.numClasses;
        delete[] classes;
        classes = new string[numClasses];
        for (int i = 0; i < numClasses; i++){
            classes[i] = s.classes[i];
        }
    }
    return *this;
}
int main(){
    Student s;
    cin >> s;
    cout << s << endl;
    s.reset();
    cin >> s;
    cout << s << endl;
    return 0;
}