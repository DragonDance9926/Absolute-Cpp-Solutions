#include <iostream>
#include <string>
using namespace std;

class DynamicStringArray{
    private:
        string *array;
        int size;
    public:
        DynamicStringArray();
        DynamicStringArray(int);
        ~DynamicStringArray();
        void add(string);
        bool remove(string);
        bool remove(int);
        string get(int);
        friend ostream& operator<<(ostream&, DynamicStringArray&);
        DynamicStringArray& operator=(DynamicStringArray&);

};

DynamicStringArray::DynamicStringArray(){
    array = NULL;
    size = 0;
}
DynamicStringArray::DynamicStringArray(int s){
    array = new string[s];
    size = s;
}
DynamicStringArray::~DynamicStringArray(){
    delete [] array;
}
void DynamicStringArray::add(string s){
    bool isempty = false;
    int i = 0;
    while(!isempty && i < size){
        if(array[i] == ""){
            array[i] = s;
            isempty = true;
        }
        i++;
    }
    if(!isempty){
        string *temp = new string[size + 1];
        for(int i = 0; i < size; i++){
            temp[i] = array[i];
        }
        temp[size] = s;
        delete [] array;
        array = temp;
        size++;
    }
}
bool DynamicStringArray::remove(string s){
    bool isfound = false;
    int i = 0;
    while(!isfound && i < size){
        if(array[i] == s){
            isfound = true;
        }
        i++;
    }
    if(isfound){
        string *temp = new string[size - 1];
        int j = 0;
        for(int i = 0; i < size; i++){
            if(array[i] != s){
                temp[j] = array[i];
                j++;
            }
        }
        delete [] array;
        array = temp;
        size--;
    }
    return isfound;
}

bool DynamicStringArray::remove(int i){
    bool isfound = false;
    if(i < size){
        isfound = true;
        string *temp = new string[size - 1];
        int j = 0;
        for(int i = 0; i < size; i++){
            if(i != i){
                temp[j] = array[i];
                j++;
            }
        }
        delete [] array;
        array = temp;
        size--;
    }
    return isfound;
}



string DynamicStringArray::get(int i){
    if(i < size){
        return array[i];
    }
    else{
        return NULL;
    }
}

ostream& operator<<(ostream& out, DynamicStringArray& dsa){
    for(int i = 0; i < dsa.size; i++){
        out << dsa.array[i] << endl;
    }
    return out;
}
DynamicStringArray& DynamicStringArray::operator=(DynamicStringArray& dsa){
    if(this != &dsa){
        delete [] array;
        array = new string[dsa.size];
        for(int i = 0; i < dsa.size; i++){
            array[i] = dsa.array[i];
        }
        size = dsa.size;
    }
    return *this;
}

int main(){
    DynamicStringArray dsa;
    int choice;
    string s;
    do {
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Get" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the string: ";
                cin >> s;
                dsa.add(s);
                break;
            case 2:
                cout << "Enter the string: ";
                cin >> s;
                dsa.remove(s);
                break;
            case 3:
                int i; 
                cout << "Enter the index: ";
                cin >> i;
                cout << dsa.get(i) << endl;
                break;
            case 4:
                cout << dsa << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 5);
    return 0;
}