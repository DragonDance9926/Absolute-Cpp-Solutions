#include <iostream>
using namespace std;

class Pizza{
    private:
        enum size{small = 10, medium = 17, large = 25};
        enum type{deep_dish = 5, hand_tossed = 4, pan_crusted = 3};
        enum topping{none = 0,cheese = 1,pepperoni = 3,sausage = 2,ham = 4,pineapple = 5,mushroom = 6,onion = 7,olive = 8,tomato = 9};
        size pizzaSize;
        type pizzaType;
        topping pizzaTopping;
        int topping_count;
        int total_cost;
        void update_cost();
    public:
        Pizza();
        void printPizza();
        int getTotalCost();
        ~Pizza();
};


Pizza::Pizza(){
    int choice;
    cout << "Enter the size of the pizza: " << endl;
    cout << "1. Small" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Large" << endl;
    do {
        cin >> choice;
        if(choice < 1 || choice > 3){
            cout << "Invalid choice. Please enter a valid choice: " << endl;
        }
    }while(choice < 1 || choice > 3);
    switch(choice){
        case 1:
            pizzaSize = small;
            break;
        case 2:
            pizzaSize = medium;
            break;
        case 3:
            pizzaSize = large;
            break;
    }
    cout << "Enter the type of the pizza: " << endl;
    cout << "1. Deep Dish" << endl;
    cout << "2. Hand Tossed" << endl;
    cout << "3. Pan Crusted" << endl;
    do {
        cin >> choice;
        if(choice < 1 || choice > 3){
            cout << "Invalid choice. Please enter a valid choice: " << endl;
        }
    }while(choice < 1 || choice > 3);
    switch(choice){
        case 1:
            pizzaType = deep_dish;
            break;
        case 2:
            pizzaType = hand_tossed;
            break;
        case 3:
            pizzaType = pan_crusted;
            break;
    }
    cout << "Enter the topping of the pizza: " << endl;
    cout << "1. None" << endl;
    cout << "2. Cheese" << endl;
    cout << "3. Pepperoni" << endl;
    cout << "4. Sausage" << endl;
    cout << "5. Ham" << endl;
    cout << "6. Pineapple" << endl;
    cout << "7. Mushroom" << endl;
    cout << "8. Onion" << endl;
    cout << "9. Olive" << endl;
    cout << "10. Tomato" << endl;
    do {
        cin >> choice;
        if(choice < 1 || choice > 10){
            cout << "Invalid choice. Please enter a valid choice: " << endl;
        }
    }while(choice < 1 || choice > 10);
    switch(choice){
        case 1:
            pizzaTopping = none;
            break;
        case 2:
            pizzaTopping = cheese;
            break;
        case 3:
            pizzaTopping = pepperoni;
            break;
        case 4:
            pizzaTopping = sausage;
            break;
        case 5:
            pizzaTopping = ham;
            break;
        case 6:
            pizzaTopping = pineapple;
            break;
        case 7:
            pizzaTopping = mushroom;
            break;
        case 8:
            pizzaTopping = onion;
            break;
        case 9:
            pizzaTopping = olive;
            break;
        case 10:
            pizzaTopping = tomato;
            break;
    }
    cout << "Enter the number of toppings: " << endl;
    cin >> topping_count;
    total_cost = pizzaSize + pizzaType + (pizzaTopping) * topping_count;
}


void Pizza::printPizza(){
    cout << "Pizza size: ";
    switch(pizzaSize){
        case small:
            cout << "Small" << endl;
            break;
        case medium:
            cout << "Medium" << endl;
            break;
        case large:
            cout << "Large" << endl;
            break;
    }
    cout << "Pizza type: ";
    switch(pizzaType){
        case deep_dish:
            cout << "Deep Dish" << endl;
            break;
        case hand_tossed:
            cout << "Hand Tossed" << endl;
            break;
        case pan_crusted:
            cout << "Pan Crusted" << endl;
            break;
    }
    cout << "Pizza topping: ";
    switch(pizzaTopping){
        case none:
            cout << "None" << endl;
            break;
        case cheese:
            cout << "Cheese" << endl;
            break;
        case pepperoni:
            cout << "Pepperoni" << endl;
            break;
        case sausage:
            cout << "Sausage" << endl;
            break;
        case ham:
            cout << "Ham" << endl;
            break;
        case pineapple:
            cout << "Pineapple" << endl;
            break;
        case mushroom:
            cout << "Mushroom" << endl;
            break;
        case onion:
            cout << "Onion" << endl;
            break;
        case olive:
            cout << "Olive" << endl;
            break;
        case tomato:
            cout << "Tomato" << endl;
            break;
    }
    cout << "Number of toppings: " << topping_count << endl;
    cout << "Total cost: " << total_cost << endl;
}


int Pizza::getTotalCost(){
    return total_cost;
}
Pizza::~Pizza(){
    cout << "Pizza object destroyed." << endl;
}


int main(){
    Pizza pizza;
    pizza.printPizza();
    return 0;
}


