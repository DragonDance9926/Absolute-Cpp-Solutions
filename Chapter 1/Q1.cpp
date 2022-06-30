#include <iostream>
using namespace std;

int main()
{
    //Print the text
    cout << "Weight of the package of cereal in ounces: ";
    //Declare the variable
    double weight;
    //Read the input
    cin >> weight;
    //convent the weight to metric tons
    double metricTons = weight / 35273.92;
    //Print the output
    cout << "Weight of the package of cereal in metric tons: " << metricTons << endl;
    //Print the number of boxes needed to yield one metric ton of cereal
    cout << "Number of boxes needed to yield one metric ton of cereal: " << static_cast<int>(35273.92 / weight) << endl;
    return 0; //End the program
}