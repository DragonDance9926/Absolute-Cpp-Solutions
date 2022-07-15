#include <iostream>
using namespace std;

class Counter{
    private:
        static int count;
        int end;
    public:
        Counter(int n);
        Counter();
        static int getCount();
        static void resetCount();
        static void incr1();
        static void incr10();
        static void incr100();
        static void incr1000();
        bool overflow();
};

int Counter::count = 0;

Counter::Counter(int n){
    end = n;
}
Counter::Counter(){
    end = 9999;
}

int Counter::getCount(){
    return count;
}
void Counter::resetCount(){
    count = 0;
}
void Counter::incr1(){
    count++;
}
void Counter::incr10(){
    count += 10;
}
void Counter::incr100(){
    count += 100;
}
void Counter::incr1000(){
    count += 1000;
}
bool Counter::overflow(){
    if (count > end){
        return true;
    }
    else{
        return false;
    }
}

int menu(Counter &c){
    int choice;
    cout << "1- Add Cent" << endl;
    cout << "2- Add Dime" << endl;
    cout << "3- Add Dollar" << endl;
    cout << "4- Add Tens of Dollar" << endl;
    cout << "5- Overflow check" << endl;
    cout << "6- Reset" << endl;
    cout << "7- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}


int main(){
    Counter count(9999);
    int choice;
    int choice2;
    do{
        choice = menu(count);
        switch(choice){
            case 1:
                do{
                    cout << "Enter the amount of cents: ";
                    cin >> choice2;
                }while (choice2 < 0 || choice2 > 9);
                for (int i = 0; i < choice2; i++){
                    count.incr1();
                }
                break;
            case 2:
                do{
                    cout << "Enter the amount of dimes: ";
                    cin >> choice2;
                }while (choice2 < 0 || choice2 > 9);
                for (int i = 0; i < choice2; i++){
                    count.incr10();
                }
                break;
            case 3:
                do{
                    cout << "Enter the amount of dollars: ";
                    cin >> choice2;
                }while (choice2 < 0 || choice2 > 9);
                for (int i = 0; i < choice2; i++){
                    count.incr100();
                }
                break;
            case 4:
                do{
                    cout << "Enter the amount of tens of dollars: ";
                    cin >> choice2;
                }while (choice2 < 0 || choice2 > 9);
                for (int i = 0; i < choice2; i++){
                    count.incr1000();
                }
                break;
            case 5:
                if (count.overflow()){
                    cout << "Overflow" << endl;
                }
                else{
                    cout << "No Overflow" << endl;
                }
                break;
            case 6:
                count.resetCount();
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }while (choice != 7);
    return 0;
}