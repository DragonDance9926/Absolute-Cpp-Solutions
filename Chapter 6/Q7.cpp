#include <iostream>
using namespace std;

class Pizza{
    private:
        enum PizzaSize{
            SMALL = 10,
            MEDIUM = 14,
            LARGE = 17
        };
        enum PizzaType{
            DEEP_DISH = 10,
            HAND_TOSSED = 5,
            PAN_CRUST = 0
        };
        PizzaSize size;
        PizzaType type;
        int pepperoni_toppings;
        int cheese_toppings;
    public:
        Pizza(){
            int choice;
            cout << "1. Small" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Large" << endl;
            cout << "Enter choice: ";
            do{
                cin >> choice;
                if (choice == 1){
                    size = PizzaSize::SMALL;
                }
                else if (choice == 2){
                    size = PizzaSize::MEDIUM;
                }
                else if (choice == 3){
                    size = PizzaSize::LARGE;
                }
                else{
                    cout << "Invalid choice" << endl;
                }
            }while (choice != 1 && choice != 2 && choice != 3);
            cout << "1. Deep dish" << endl;
            cout << "2. Hand-tossed" << endl;
            cout << "3. Pan-crust" << endl;
            cout << "Enter choice: ";
            do{
                cin >> choice;
                if (choice == 1){
                    type = PizzaType::DEEP_DISH;
                }
                else if (choice == 2){
                    type = PizzaType::HAND_TOSSED;
                }
                else if (choice == 3){
                    type = PizzaType::PAN_CRUST;
                }
                else{
                    cout << "Invalid choice" << endl;
                }
            }while (choice != 1 && choice != 2 && choice != 3);
            cout << "Enter number of pepperoni toppings: ";
            cin >> pepperoni_toppings;
            cout << "Enter number of cheese toppings: ";
            cin >> cheese_toppings;
        }
        void output();
        double price();
        ~Pizza(){
            cout << "Pizza destroyed" << endl;
        }
};

void Pizza::output(){
    std::cout << "Size: ";
    if (size == PizzaSize::SMALL){
        std::cout << "Small" << std::endl;
    }
    else if (size == PizzaSize::MEDIUM){
        std::cout << "Medium" << std::endl;
    }
    else if (size == PizzaSize::LARGE){
        std::cout << "Large" << std::endl;
    }
    std::cout << "Type: ";
    if (type == PizzaType::DEEP_DISH){
        std::cout << "Deep dish" << std::endl;
    }
    else if (type == PizzaType::HAND_TOSSED){
        std::cout << "Hand-tossed" << std::endl;
    }
    else if (type == PizzaType::PAN_CRUST){
        std::cout << "Pan-crust" << std::endl;
    }
    std::cout << "Pepperoni toppings: " << pepperoni_toppings << std::endl;
    std::cout << "Cheese toppings: " << cheese_toppings << std::endl;
}

double Pizza::price(){
    double price = 0;
    if (size == PizzaSize::SMALL){
        price += 10;
    }
    else if (size == PizzaSize::MEDIUM){
        price += 14;
    }
    else if (size == PizzaSize::LARGE){
        price += 17;
    }
    if (type == PizzaType::DEEP_DISH){
        price += 10;
    }
    else if (type == PizzaType::HAND_TOSSED){
        price += 5;
    }
    else if (type == PizzaType::PAN_CRUST){
        price += 0;
    }
    price += pepperoni_toppings * 0.8;
    price += cheese_toppings * 0.6;
    return price;
}

int main(){
    char choice;
    do{
        Pizza pizza;
        pizza.output();
        cout << "Price: " << pizza.price() << endl;
        cout << "Continue? (y/n): ";
        cin >> choice;
    }while (choice == 'y');
    return 0;
}