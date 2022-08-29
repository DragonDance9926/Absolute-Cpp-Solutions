#include<iostream>
#include<string>
using namespace std;

template <class T>
class set_of_item{
    private:
        T *arr;
        int capacity;
        int size;
    public:
        set_of_item(){
            arr = NULL;
            capacity = 0;
            size = 0;
        }
        set_of_item(int n){
            arr = new T[n];
            capacity = n;
            size = 0;
        }
        set_of_item(T arr[], int n){
            this->arr = new T[n];
            capacity = n;
            size = 0;
            for (int i = 0; i < n; i++){
                this->arr[i] = arr[i];
                size++;
            }
        }
        set_of_item(set_of_item &s){
            arr = new T[s.capacity];
            capacity = s.capacity;
            size = s.size;
            for (int i = 0; i < s.size; i++){
                arr[i] = s.arr[i];
            }
        }
        set_of_item& operator=(set_of_item &s){
            if (this != &s){
                delete [] arr;
                arr = new T[s.capacity];
                capacity = s.capacity;
                size = s.size;
                for (int i = 0; i < s.size; i++){
                    arr[i] = s.arr[i];
                }
            }
            return *this;
        }
        void add(T num){
            if (size == capacity){
                cout << "The set is full. Reallocating memory..." << endl;
                T* temp = new T[++capacity];
                for (int i = 0; i < size; i++){
                    temp[i] = arr[i];
                }
                temp[size++] = num;
                delete [] arr;
                arr = temp;
            }
            else{
                arr[size++] = num;
            }
            cout << "Added " << num << " to the set." << endl;
        }
        void pop(){
            if (size == 0){
                cout << "The set is empty." << endl;
            }
            else{
                cout << "Popped " << arr[--size] << " from the set." << endl;
            }
        }
        T operator[] (int i){
            if (i < 0 || i >= size){
                cout << "Index out of bounds." << endl;
                return 0;
            }
            return arr[i];
        }
        friend ostream& operator<<(ostream &out, set_of_item &s){
            cout << "{";
            for (int i = 0; i < s.size; i++){
                out << s.arr[i] << " ";
            }
            cout << "}" << endl;
            return out;
        }
        friend istream& operator>>(istream &in, set_of_item &s){
            int n;
            cout << "Enter the number of elements in the set: ";
            in >> n;
            s.arr = new T[n];
            s.capacity = n;
            s.size = 0;
            for (int i = 0; i < n; i++){
                T num;
                cout << "Enter element " << i + 1 << ": ";
                in >> num;
                s.add(num);
            }
            return in;
        }
        ~set_of_item(){
            delete []arr;
        }
};

int main(){
    set_of_item<int> s;
    cin >> s;
    cout << s;
    int choice;
    do{
        cout << "1. Add an element to the set." << endl;
        cout << "2. Pop an element from the set." << endl;
        cout << "3. Exit." << endl;
        cout << "4. Print the set." << endl;
        cout << "5. Access an element in the set." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                int num;
                cout << "Enter the element to add: ";
                cin >> num;
                s.add(num);
                cout << s;
                break;
            case 2:
                s.pop();
                cout << s;
                break;
            case 3:
                break;
            case 4:
                cout << s;
                break;
            case 5:
                int i;
                cout << "Enter the index of the element: ";
                cin >> i;
                cout << s[i] << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }while(choice != 3);
}