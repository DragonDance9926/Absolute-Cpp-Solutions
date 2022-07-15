#include <iostream>
#include <string>
using namespace std;

class Month{
    private:
        string first3letters; //first three letters of the month name
    public:
        Month(string name);
        Month();
        Month(int m);
        void outputint();
        void outputstring();
};

Month::Month(string name){
    //convert name to lowercase
    for (int i = 0; i < name.length(); i++){
        name[i] = tolower(name[i]);
    }
    //Only use the first three letters of the name
    if (name.length() > 3){
        name = name.substr(0, 3);
    }
    //check if the name is valid
    if (name == "jan" || name == "feb" || name == "mar" || name == "apr" || name == "may" || name == "jun" || name == "jul" || name == "aug" || name == "sep" || name == "oct" || name == "nov" || name == "dec"){
        first3letters = name;
    }
    else{
        first3letters = "jan";
    }
}

Month::Month(){
    first3letters = "jan";
}
Month::Month(int m){
    switch(m){
        case 1:
            first3letters = "jan";
            break;
        case 2:
            first3letters = "feb";
            break;
        case 3:
            first3letters = "mar";
            break;
        case 4:
            first3letters = "apr";
            break;
        case 5:
            first3letters = "may";
            break;
        case 6:
            first3letters = "jun";
            break;
        case 7:
            first3letters = "jul";
            break;
        case 8:
            first3letters = "aug";
            break;
        case 9:
            first3letters = "sep";
            break;
        case 10:
            first3letters = "oct";
            break;
        case 11:
            first3letters = "nov";
            break;
        case 12:
            first3letters = "dec";
            break;
        default:
            first3letters = "jan";
            break;
    }
}

void Month::outputint(){
    if (first3letters == "jan"){
        cout << 1;
    }
    else if (first3letters == "feb"){
        cout << 2;
    }
    else if (first3letters == "mar"){
        cout << 3;
    }
    else if (first3letters == "apr"){
        cout << 4;
    }
    else if (first3letters == "may"){
        cout << 5;
    }
    else if (first3letters == "jun"){
        cout << 6;
    }
    else if (first3letters == "jul"){
        cout << 7;
    }
    else if (first3letters == "aug"){
        cout << 8;
    }
    else if (first3letters == "sep"){
        cout << 9;
    }
    else if (first3letters == "oct"){
        cout << 10;
    }
    else if (first3letters == "nov"){
        cout << 11;
    }
    else if (first3letters == "dec"){
        cout << 12;
    }
}
void Month::outputstring(){
    if (first3letters == "jan"){
        cout << "January";
    }
    else if (first3letters == "feb"){
        cout << "February";
    }
    else if (first3letters == "mar"){
        cout << "March";
    }
    else if (first3letters == "apr"){
        cout << "April";
    }
    else if (first3letters == "may"){
        cout << "May";
    }
    else if (first3letters == "jun"){
        cout << "June";
    }
    else if (first3letters == "jul"){
        cout << "July";
    }
    else if (first3letters == "aug"){
        cout << "August";
    }
    else if (first3letters == "sep"){
        cout << "September";
    }
    else if (first3letters == "oct"){
        cout << "October";
    }
    else if (first3letters == "nov"){
        cout << "November";
    }
    else if (first3letters == "dec"){
        cout << "December";
    }
}