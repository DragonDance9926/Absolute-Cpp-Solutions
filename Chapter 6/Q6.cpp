#include <iostream>
using namespace std;

class Odometer{
    double miles_driven;
    double miles_per_gallon;
    double fuel_wasted;
    public:
    //Inıtilaze the odometer to 0
    void initialize(){
        miles_driven = 0;
        miles_per_gallon = 0;
        fuel_wasted = 0;
    }
    void add_miles_driven(double m){
        miles_driven += m;
    }
    void set_miles_per_gallon(double mpg){
        miles_per_gallon = mpg;
    }
    void add_fuel_wasted(){
        fuel_wasted += miles_driven * miles_per_gallon;
    }
    double get_miles_driven(){
        return miles_driven;
    }
    double get_miles_per_gallon(){
        return miles_per_gallon;
    }
    double get_fuel_wasted(){
        return fuel_wasted;
    }
};

int menu(Odometer &odometer){
    cout << "Miles driven: " << odometer.get_miles_driven() << endl;
    cout << "Miles per gallon: " << odometer.get_miles_per_gallon() << endl;
    cout << "Fuel wasted: " << odometer.get_fuel_wasted() << endl;
    cout << "1. Add miles driven" << endl;
    cout << "2. Set miles per gallon" << endl;
    cout << "3. Reset" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main(){
    Odometer odometer;
    odometer.initialize();
    int choice;
    do{
        choice = menu(odometer);
        switch (choice){
            case 1:
                cout << "Enter miles driven: ";
                double m;
                cin >> m;
                if (odometer.get_miles_per_gallon() == 0){
                    cout << "Miles per gallon is not set" << endl;
                }
                else{
                    odometer.add_miles_driven(m);
                    odometer.add_fuel_wasted();
                }
                break;
            case 2:
                if (odometer.get_miles_per_gallon() != 0){
                    cout << "Miles per gallon is not 0" << endl;
                }
                else{
                    cout << "Enter miles per gallon: " << endl;
                    double mpg;
                    cin >> mpg;
                    odometer.set_miles_per_gallon(mpg);
                }
                break;
            case 3:
                odometer.initialize();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }while(choice != 4);
    return 0;
}

