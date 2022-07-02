#include <iostream>
using namespace std;

bool isLeapYear(int year);
int getCentury(int year);
int getYear(int year);
int getMonth(int month, int year);
string getDay(int remainder);

int main(){
    int year;
    int month;
    int day;
    cout << "Enter a year: ";
    cin >> year;
    cout << "Enter a month: ";
    cin >> month;
    cout << "Enter a day: ";
    cin >> day;
    int century = getCentury(year);
    int yearvalue = getYear(year);
    int monthvalue = getMonth(month, year);
    int sum = day + monthvalue + yearvalue + century;
    int remainder = sum % 7;
    string dayname = getDay(remainder);
    cout << "The day is " << dayname << endl;
    return 0;
}

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int getCentury(int year){
    int century = year / 100;
    int remainder = century % 4;
    int res = (3 - remainder);
    return res*2;
}
int getYear(int year){
    int year_twolast = year % 100;
    int divide_by_four = year_twolast / 4;
    return year_twolast + divide_by_four;
}
int getMonth(int month, int year){
    switch (month){
        case 1:
            return isLeapYear(year) ? 6 : 0;
        case 2:
            return isLeapYear(year) ? 2 : 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
    }
}

string getDay(int remainder){
    switch (remainder){
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid";
    }
}