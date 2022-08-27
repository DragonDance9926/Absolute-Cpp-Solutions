#include <iostream>
#include <string>
using namespace std;

class Figure{
    public:
        virtual void draw(){
            cout << "Figure has been drawn" << endl;
        }
        virtual void erase(){
            cout << "Figure has been erased" << endl;
        }
        virtual void center(){
            cout << "Figure has been centered" << endl;
        }
};

class Triangle: public Figure{
    public:
        Triangle(){
            cout << "Triangle has been created" << endl;
        }
        void draw(){
            cout << "Triangle has been drawn" << endl;
        }
        void erase(){
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
            cout << "Rectangle has been drawn" << endl;
        }
        void erase(){
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
    Triangle t;
    f = &t;
    f->draw();
    f->erase();
    f->center();
    Rectangle r;
    f = &r;
    f->draw();
    f->erase();
    f->center();
    return 0;
}