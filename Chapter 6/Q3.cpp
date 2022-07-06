#include <iostream>
#include <cmath>

class Point{
    int x;
    int y;
public:
    int menu();
    void set_point(int x1, int y1){
        x = x1;
        y = y1;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    void print_point(){
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    void move_point(int x1, int y1){
        x += x1;
        y += y1;
    }
    void rotate_point(int angle){
        //Convert degress to radians
        double rad = angle * (M_PI / 180);
        double x1 = x;
        double y1 = y;
        x = x1 * cos(rad) - y1 * sin(rad);
        y = x1 * sin(rad) + y1 * cos(rad);
    }
};


int main(){
    Point p;
    std::cout << "Enter x: ";
    int x;
    std::cin >> x;
    std::cout << "Enter y: ";
    int y;
    std::cin >> y;
    p.set_point(x,y);
    int choice;
    do{
        choice = p.menu();
        switch (choice){
            case 1:
                std::cout << "x is " << p.get_x() << std::endl;
                break;
            case 2:
                std::cout << "y is " << p.get_y() << std::endl;
                break;
            case 3:
                p.print_point();
                break;
            case 4:
                std::cout << "How much to move x: ";
                int x1;
                std::cin >> x1;
                std::cout << "How much to move y: ";
                int y1;
                std::cin >> y1;
                p.move_point(x1,y1);
                break;
            case 5:
                std::cout << "How much to rotate: ";
                int angle;
                std::cin >> angle;
                if (angle % 90 != 0){
                    std::cout << "Only 90 degree angles are allowed" << std::endl;
                }
                else{
                    p.rotate_point(angle);
                }
                break;
            case 6:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }while (choice != 6);
    return 0;
}

int Point::menu(){
    int choice;
    std::cout << "1. Get x" << std::endl;
    std::cout << "2. Get y" << std::endl;
    std::cout << "3. Print point" << std::endl;
    std::cout << "4. Move point" << std::endl;
    std::cout << "5. Rotate point" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}