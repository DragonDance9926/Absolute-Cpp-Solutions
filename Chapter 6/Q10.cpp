#include <iostream>
using namespace std;

class Temperature{
    private:
        enum Temp_type{
            CELSIUS,
            FAHRENHEIT,
            KELVIN
        };
        Temp_type type;
        double value;
    public:
        Temperature(){
            cout << "Enter the type of temperature: ";
            char ch;
            cin >> ch;
            bool flag = false;
            do{
                switch (ch){
                    case 'c':
                        type = CELSIUS;
                        flag = true;
                        break;
                    case 'f':
                        type = FAHRENHEIT;
                        flag = true;
                        break;
                    case 'k':
                        type = KELVIN;
                        flag = true;
                        break;
                    default:
                        cout << "Invalid input. Try again: ";
                        cin >> ch;
                }
            }while (!flag);
            cout << "Enter the value: ";
            cin >> value;
        }
        void return_celsius(){
            double temp;
            switch (type){
                case CELSIUS:
                    temp = value;
                    cout << "The temperature is " << temp << " C" << endl;
                    break;
                case FAHRENHEIT:
                    temp = (value - 32) * 5/9;
                    cout << "The temperature is " << temp << " C" << endl;
                    break;
                case KELVIN:
                    temp = value - 273.15;
                    cout << "The temperature is " << temp << " C" << endl;
                    break;
            }
        }
        void return_fahrenheit(){
            double temp;
            switch (type){
                case CELSIUS:
                    temp = value * 9/5 + 32;
                    cout << "The temperature is " << temp << " F" << endl;
                    break;
                case FAHRENHEIT:
                    temp = value;
                    cout << "The temperature is " << temp << " F" << endl;
                    break;
                case KELVIN:
                    temp = value * 9/5 - 459.67;
                    cout << "The temperature is " << temp << " F" << endl;
                    break;
            }
        }
        void return_kelvin(){
            double temp;
            switch (type){
                case CELSIUS:
                    temp = value + 273.15;
                    cout << "The temperature is " << temp << " K" << endl;
                    break;
                case FAHRENHEIT:
                    temp = (value + 459.67) * 5/9;
                    cout << "The temperature is " << temp << " K" << endl;
                    break;
                case KELVIN:
                    temp = value;
                    cout << "The temperature is " << temp << " K" << endl;
                    break;
            }
        }
        char get_type(){
            switch (type){
                case CELSIUS:
                    return 'c';
                case FAHRENHEIT:
                    return 'f';
                case KELVIN:
                    return 'k';
            }
        }
        double get_value(){
            return value;
        }
        ~Temperature(){
            cout << "Destructor called" << endl;
        }
};

int menu(Temperature &t){
    cout << "Type of temperature: ";
    switch (t.get_type()){
        case 'c':
            cout << "Celsius" << endl;
            break;
        case 'f':
            cout << "Fahrenheit" << endl;
            break;
        case 'k':
            cout << "Kelvin" << endl;
            break;
    }
    cout << "Value: " << t.get_value() << endl;
    cout << "1. Return Celsius\n2. Return Fahrenheit\n3. Return Kelvin\n4. Set new tempreature\n5. Exit\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main(){
    Temperature t;
    int choice;
    do{
        choice = menu(t);
        switch (choice){
            case 1:
                t.return_celsius();
                break;
            case 2:
                t.return_fahrenheit();
                break;
            case 3:
                t.return_kelvin();
                break;
            case 4:
                t.~Temperature();
                //Create the new object
                t = Temperature();
                break;
            case 5:
                break;
        }
    }while (choice != 5);
    return 0;
}

