#include <iostream>
using namespace std;

class Money{
    private:
        int dollar;
        int cent;
    public:
        Money(){
            dollar = 0;
            cent = 0;
        }
        void set_dollar(int d){
            dollar = d;
        }
        void set_cent(int c){
            cent = c;
        }
        int get_dollar(){
            return dollar;
        }
        int get_cent(){
            return cent;
        }
        void display(){
            cout << "$" << dollar << "." << cent << endl;
        }
        void add_dollar(int d){
            dollar += d;
        }
        void add_cent(int c){
            cent += c;
        }
        double monetary_value(){
            return dollar + (cent/100.0);
        }
};

int main(){
    Money m1;
    int d,c;
    cout << "Enter the dollar: ";
    cin >> d;
    cout << "Enter the cent: ";
    cin >> c;
    m1.set_dollar(d);
    m1.set_cent(c);
    int choice;
    do{
        cout << "1. Add dollar\n2. Add cent\n3. Display\n4. Monetary value\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the dollar: ";
                cin >> d;
                m1.add_dollar(d);
                break;
            case 2:
                cout << "Enter the cent: ";
                cin >> c;
                m1.add_cent(c);
                break;
            case 3:
                m1.display();
                break;
            case 4:
                cout << "Monetary value: " << m1.monetary_value() << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }while(choice != 5);
    return 0;
}