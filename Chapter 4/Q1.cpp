#include <iostream>
using namespace std;

void input(int&,int&);
char ampm(int);
void conver24to12(int&,int&);

int main(){
    int hour,minute;
    char sign;
    input(hour,minute);
    sign = ampm(hour);
    conver24to12(hour,minute);
    cout<<hour<<":"<<minute<<" "<<sign<<endl;
    return 0;
}

void input(int& hours, int& minutes){
    cout << "Enter the hours and minutes in 24-hour format: \n";
    cin >> hours >> minutes;
}
char ampm(int hours){
    if(hours < 12){
        return 'a';
    }
    else{
        return 'p';
    }
}
void conver24to12(int& hours, int& minutes){
    if(hours > 12){
        hours -= 12;
    }
}