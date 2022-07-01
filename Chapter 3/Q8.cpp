#include <iostream>
using namespace std;

string numtostr(int n){
    switch (n){
        case 19:
            return "nineteen";
        case 18:
            return "eighteen";
        case 17:
            return "seventeen";
        case 16:
            return "sixteen";
        case 15:
            return "fifteen";
        case 14:
            return "fourteen";
        case 13:
            return "thirteen";
        case 12:
            return "twelve";
        case 11:
            return "eleven";
        case 10:
            return "ten";
    }
    string res = "";
    switch (n){
        case 90 ... 99:
            res += "ninety";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 80 ... 89:
            res += "eighty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 70 ... 79:
            res += "seventy";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 60 ... 69:
            res += "sixty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 50 ... 59:
            res += "fifty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 40 ... 49:
            res += "forty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 30 ... 39:
            res += "thirty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        case 20 ... 29:
            res += "twenty";
            if (n % 10 != 0){
                res += "-";
            }
            break;
        default:
            break;
    }
    switch (n % 10){
        case 9:
            res += "nine";
            break;
        case 8:
            res += "eight";
            break;
        case 7:
            res += "seven";
            break;
        case 6:
            res += "six";
            break;
        case 5:
            res += "five";
            break;
        case 4:
            res += "four";
            break;
        case 3:
            res += "three";
            break;
        case 2:
            res += "two";
            break;
        case 1:
            res += "one";
            break;
        default:
            break;
    }
    return res;
}

int main(){
    for(int i = 99; i > 1; i--){
        cout << numtostr(i) << " bottles of beer on the wall,\n" << numtostr(i) << " bottles of beer.\n";
        cout << "Take one down, pass it around,\n";
    }
    cout << "One bottle of beer on the wall.\n";
    cout << "One bottle of beer.\n";
    cout << "Take one down, pass it around,\n";
    cout << "No more bottles of beer on the wall.\n";
    return 0;
}