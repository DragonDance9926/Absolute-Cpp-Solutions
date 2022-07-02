#include <iostream>
using namespace std;

void input(int& old_arg1, double& old_arg2,int& choice1,int& choice2);
void convert(int old_arg1, double old_arg2,int choice1,int choice2,int& new_arg1,double& new_arg2);
void output(int new_arg1, double new_arg2,int choice1,int choice2);


int main(){
    double new_arg2,old_arg2;
    int new_arg1,old_arg1,choice1,choice2;
    bool flag=true;
    while(flag){
        input(old_arg1,old_arg2,choice1,choice2);
        convert(old_arg1,old_arg2,choice1,choice2,new_arg1,new_arg2);
        output(new_arg1,new_arg2,choice1,choice2);
        cout<<"Do you want to continue?(y/n)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='n'){
            flag=false;
        }
    }
    return 0;
}

void input(int& old_arg1, double& old_arg2,int& choice1,int& choice2){
    //Menu for length or weight
    cout << "1-Length\n";
    cout << "2-Weight\n";
    cout << "Enter your choice: ";
    cin >> choice1;
    switch (choice1){
        case 1:
            //Menu for length units
            cout << "1- Meters-Centimeters to Feet-Inches\n";
            cout << "2- Feet-Inches to Meters-Centimeters\n";
            cout << "Enter your choice: ";
            cin >> choice2;
            switch (choice2){
                case 1:
                    //Taking input for meters and centimeters
                    cout << "Enter the length in meters and centimeters: ";
                    cin >> old_arg1 >> old_arg2;
                    break;
                case 2:
                    //Taking input for feet and inches
                    cout << "Enter the length in feet and inches: ";
                    cin >> old_arg1 >> old_arg2;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 2:
            //Menu for weight units
            cout << "1- Kilograms-Grams to Pounds-Ounces\n";
            cout << "2- Pounds-Ounces to Kilograms-Grams\n";
            cout << "Enter your choice: ";
            cin >> choice2;
            switch (choice2){
                case 1:
                    //Taking input for kilograms and grams
                    cout << "Enter the weight in kilograms and grams: ";
                    cin >> old_arg1 >> old_arg2;
                    break;
                case 2:
                    //Taking input for pounds and ounces
                    cout << "Enter the weight in pounds and ounces: ";
                    cin >> old_arg1 >> old_arg2;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
    }
}

void convert(int old_arg1, double old_arg2,int choice1,int choice2,int& new_arg1,double& new_arg2){
    //Converting length
    double total_centimeters;
    double total_inches;
    double total_grams;
    double total_ounces;
    switch (choice1){
        case 1:
            switch (choice2){
                case 1:
                    //Converting meters to feet and inches
                    total_centimeters = old_arg1 * 100 + old_arg2;
                    new_arg2 = total_centimeters * 0.393700787;
                    new_arg1 = new_arg2 / 12;
                    new_arg2 -= new_arg1 * 12;
                    break;
                case 2:
                    //Converting feet and inches to meters and centimeters
                    total_inches = old_arg1 * 12 + old_arg2;
                    new_arg2 = total_inches * 2.54;
                    new_arg1 = new_arg2 / 100;
                    new_arg2 -= new_arg1 * 100;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 2:
            switch(choice2){
                case 1:
                    //Converting kilograms to pounds and ounces
                    total_grams = old_arg1 * 1000 + old_arg2;
                    //Convert grams to ounces
                    new_arg2 = total_grams * 0.035274;
                    //Convert ounces to pounds
                    new_arg1 = new_arg2 / 16;
                    new_arg2 -= new_arg1 * 16;
                    break;
                case 2:
                    //Converting pounds and ounces to kilograms and grams
                    total_ounces = old_arg1 * 16 + old_arg2;
                    new_arg2 = total_ounces * 28.3495231;
                    new_arg1 = new_arg2 / 1000;
                    new_arg2 -= new_arg1 * 1000;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

void output(int new_arg1, double new_arg2,int choice1,int choice2){
    //Outputting length
    switch (choice1){
        case 1:
            switch (choice2){
                case 1:
                    //Outputting feet and inches
                    cout << "The length in feet and inches is: " << new_arg1 << " feet " << new_arg2 << " inches.\n";
                    break;
                case 2:
                    //Outputting meters and centimeters
                    cout << "The length in meters and centimeters is: " << new_arg1 << " meters " << new_arg2 << " centimeters.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 2:
            switch(choice2){
                case 1:
                    //Outputting pounds and ounces
                    cout << "The weight in pounds and ounces is: " << new_arg1 << " pounds " << new_arg2 << " ounces.\n";
                    break;
                case 2:
                    //Outputting kilograms and grams
                    cout << "The weight in kilograms and grams is: " << new_arg1 << " kilograms " << new_arg2 << " grams.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}



