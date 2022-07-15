#include <iostream>
using namespace std;

class Money{
    private:
        int dollars;
        int cents;
    public:
        Money();
        Money(int, int);
        void add(Money);
        void subtract(Money);
        void add(int, int);
        void subtract(int, int);
        void printMoney();
        ~Money();
};

Money::Money(){
    dollars = 0;
    cents = 0;
}
Money::Money(int d, int c){
    dollars = d;
    cents = c;
}
void Money::printMoney(){
    cout << "$" << dollars << "." << cents << endl;
}
void Money::add(Money m){
    dollars += m.dollars;
    cents += m.cents;
    if(cents >= 100){
        dollars += cents/100;
        cents %= 100;
    }
}
void Money::subtract(Money m){
    dollars -= m.dollars;
    cents -= m.cents;
    if(cents < 0){
        dollars -= cents/100;
        cents %= 100;
    }
}
void Money::add(int d, int c){
    dollars += d;
    cents += c;
    if(cents >= 100){
        dollars += cents/100;
        cents %= 100;
    }
}
void Money::subtract(int d, int c){
    dollars -= d;
    cents -= c;
    if(cents < 0){
        dollars -= cents/100;
        cents %= 100;
    }
}
Money::~Money(){
    cout << "Money object destroyed." << endl;
}
int main(){
    Money m1;
    Money m2(1, 50);
    Money m3(2, 50);
    m1.add(2, 50);
    m1.add(m2);
    m1.add(m3);
    m1.printMoney();
    return 0;
}