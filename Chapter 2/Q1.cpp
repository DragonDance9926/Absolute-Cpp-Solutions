#include <iostream>
using namespace std;
int main(){
    double cost_of_item;
    int years;
    double rate_of_inflation;
    cout << "Enter the cost of the item: ";
    cin >> cost_of_item;
    cout << "Enter the number of years: ";
    cin >> years;
    cout << "Enter the rate of inflation: ";
    cin >> rate_of_inflation;
    rate_of_inflation = rate_of_inflation / 100;
    for (int i = 0; i < years; i++){
        cost_of_item += cost_of_item * rate_of_inflation;
    }
    cout << "The cost of the item after " << years << " years is " << cost_of_item << endl;
    return 0;
}