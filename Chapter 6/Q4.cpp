#include <iostream>

using namespace std;

class GasPump{
    double costperliter;
    double amount_charged;
    double amount_dispensed;
    public:
        void set_costperliter(double c){
            costperliter = c;
        }
        void add_amount_dispensed(double a){
            amount_dispensed += a;
        }
        void set_amount_charged(double c){
            amount_charged = amount_dispensed * costperliter;
        }
        double get_amount_charged(){
            return amount_charged;
        }
        double get_amount_dispensed(){
            return amount_dispensed;
        }
        double get_costperliter(){
            return costperliter;
        }
        void reset(){
            amount_charged = 0;
            amount_dispensed = 0;
        }
};

int menu(GasPump &c){
    cout << "Cost per liter: " << c.get_costperliter() << endl;
    cout << "Amount charged: " << c.get_amount_charged() << endl;
    cout << "Amount dispensed: " << c.get_amount_dispensed() << endl;
    cout << "1. Add amount dispensed" << endl;
    cout << "2. Reset" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main(){
    GasPump c;
    c.set_costperliter(27.46);
    c.reset();
    int choice;
    do{
        choice = menu(c);
        switch (choice){
            case 1:
                cout << "Enter amount dispensed: ";
                double a;
                cin >> a;
                c.add_amount_dispensed(a);
                c.set_amount_charged(a);
                break;
            case 2:
                c.reset();
                break;
            case 3:
                break;
        }
    }while(choice != 3);
    return 0;
}