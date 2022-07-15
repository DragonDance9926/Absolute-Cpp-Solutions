#include <iostream>
#include <string>
using namespace std;

class Month{
    private:
        enum months{
            January = 1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };
        months month;
    public:
        Month(int m);
        Month(string name);
        Month();
        void outputint();
        void outputstring();
};

Month::Month(int m){
    if (m > 0 && m < 13){
        month = static_cast<months>(m);
    }
    else{
        month = January;
    }
}
Month::Month(){
    month = January;
}
Month::Month(string name){
    //convert name to lowercase
    for (int i = 0; i < name.length(); i++){
        name[i] = tolower(name[i]);
    }
    //Only use the first three letters of the name
    if (name.length() > 3){
        name = name.substr(0, 3);
    }
    if (name == "jan"){
        month = January;
    }
    else if (name == "feb"){
        month = February;
    }
    else if (name == "mar"){
        month = March;
    }
    else if (name == "apr"){
        month = April;
    }
    else if (name == "may"){
        month = May;
    }
    else if (name == "jun"){
        month = June;
    }
    else if (name == "jul"){
        month = July;
    }
    else if (name == "aug"){
        month = August;
    }
    else if (name == "sep"){
        month = September;
    }
    else if (name == "oct"){
        month = October;
    }
    else if (name == "nov"){
        month = November;
    }
    else if (name == "dec"){
        month = December;
    }
    else{
        month = January;
    }
}

void Month::outputint(){
    cout << "The month is " << month << endl;
}

void Month::outputstring(){
    switch (month){
        case January:
            cout << "January" << endl;
            break;
        case February:
            cout << "February" << endl;
            break;
        case March:
            cout << "March" << endl;
            break;
        case April:
            cout << "April" << endl;
            break;
        case May:
            cout << "May" << endl;
            break;
        case June:
            cout << "June" << endl;
            break;
        case July:
            cout << "July" << endl;
            break;
        case August:
            cout << "August" << endl;
            break;
        case September:
            cout << "September" << endl;
            break;
        case October:
            cout << "October" << endl;
            break;
        case November:
            cout << "November" << endl;
            break;
        case December:
            cout << "December" << endl;
            break;
    }
}

int main(){
    Month m1(11);
    Month m2("DeC");
    Month m3;
    m1.outputint();
    m2.outputstring();
    m3.outputstring();
    return 0;
}