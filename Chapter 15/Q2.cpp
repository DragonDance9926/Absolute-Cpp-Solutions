#include <iostream>
#include <string>
using namespace std;

class Figure{
    public:
        virtual void draw(){
            cout << "Unkown Figure" << endl;
        }
        virtual void erase(){
            cout << "Unkown Figure" << endl;
        }
        virtual void center(){
            cout << "Unkown Figure" << endl;
        }
};

class Triangle: public Figure{
    public:
        Triangle(){
            cout << "Triangle has been created" << endl;
        }
        void draw(){
            cout << "   *   " << endl;
            cout << "  ***  " << endl;
            cout << " ***** " << endl;
        }
        void erase(){
            fflush(stdout);
            cout << "Triangle has been erased" << endl;
        }
        void center(){
            cout << "Triangle has been centered" << endl;
        }
};

class Rectangle: public Figure{
    public:
        Rectangle(){
            cout << "Rectangle has been created" << endl;
        }
        void draw(){
            cout << "*****" << endl;
            cout << "*   *" << endl;
            cout << "*****" << endl;
        }
        void erase(){
            fflush(stdout);
            cout << "Rectangle has been erased" << endl;
        }
        void center(){
            cout << "Rectangle has been centered" << endl;
        }
};

int main(){
    /*
    Without virtual functions, the derived class will call the base class's functions.
    */
    Figure *f;
    cout << "1- Triangle" << endl;
    cout << "2- Rectangle" << endl;
    int choice;
    cin >> choice;
    if(choice == 1){
        Triangle t;
        f = &t;
    }
    else if(choice == 2){
        Rectangle r;
        f = &r;
    }
    else{
        f = new Figure();
    }
    do {
        cout << "1- Draw" << endl;
        cout << "2- Erase" << endl;
        cout << "3- Center" << endl;
        cout << "4- Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                f->draw();
                break;
            case 2:
                f->erase();
                break;
            case 3:
                f->center();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 4);
    return 0;
}