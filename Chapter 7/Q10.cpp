#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class BoxOfProduct
{
private:
    static int recipe_flyers;
    enum agriculture_type
    {
        tomatillo,
        broccoli,
        tomato,
        kiwi,
        kale
    };
    agriculture_type t1;
    agriculture_type t2;
    agriculture_type t3;
    bool recipe_flyer;

public:
    BoxOfProduct();
    static void decrease_recipe_flyers();
    void print();
    static int get_recipe_flyers();
};

int BoxOfProduct::recipe_flyers = 5;

BoxOfProduct::BoxOfProduct()
{
    t1 = static_cast<agriculture_type>(rand() % 5);
    t2 = static_cast<agriculture_type>(rand() % 5);
    t3 = static_cast<agriculture_type>(rand() % 5);
    if (recipe_flyers > 0 && (t1 == agriculture_type::tomatillo || t2 == agriculture_type::tomatillo || t3 == agriculture_type::tomatillo))
    {
        recipe_flyer = true;
        decrease_recipe_flyers();
    }
    else
    {
        recipe_flyer = false;
    }
}

void BoxOfProduct::decrease_recipe_flyers()
{
    recipe_flyers--;
}

void BoxOfProduct::print()
{
    auto type = [](agriculture_type t) -> string
    {
        switch (t)
        {
        case tomatillo:
            return "Tomatillo";
        case broccoli:
            return "Broccoli";
        case tomato:
            return "Tomato";
        case kiwi:
            return "Kiwi";
        case kale:
            return "Kale";
        }
    };
    cout << "Box of product: " << type(t1) << ", " << type(t2) << ", " << type(t3) << endl;
    if (recipe_flyer)
    {
        cout << "Salsa verde recipe." << endl;
    }
}

int BoxOfProduct::get_recipe_flyers()
{
    return recipe_flyers;
}

int main(){
    srand(time(NULL));
    char choice;
    int remaing_recipe_flyers;
    do{
        BoxOfProduct b;
        remaing_recipe_flyers = BoxOfProduct::get_recipe_flyers();
        b.print();
        cout << "Continue? (y/n): ";
        cin >> choice;
    }while(choice == 'y' && remaing_recipe_flyers > 0);
    cout << "No more recipe flyers." << endl;
    return 0;
}
