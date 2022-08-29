#include <iostream>
#include <string>
using namespace std;

template <class T, class V>
class Pair{
    private:
        T key;
        V value;
    public:
        Pair(T key, V value){
            this->key = key;
            this->value = value;
        }
        Pair(){
            static T k;
            static V v;
            key = k;
            value = v;

        }
        Pair(Pair &p){
            key = p.key;
            value = p.value;
        }
        T getKey(){
            return key;
        }
        V getValue(){
            return value;
        }
        void setKey(T key){
            this->key = key;
        }
        void setValue(V value){
            this->value = value;
        }
        friend ostream& operator<<(ostream &out, Pair<T, V> &p){
            out << "Key:" << p.key << " Value:" << p.value; 
            return out;
        }
        friend istream& operator>>(istream &in, Pair<T, V> &p){
            cout << "Enter key: ";
            in >> p.key;
            cout << "Enter value: ";
            in >> p.value;
            return in;
        }
};

int main(){
    Pair<int, string> p1;
    Pair<int, string> p2(1, "Hello");
    Pair<int, string> p3(p2);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cin >> p1;
    cout << p1 << endl;
    return 0;
}