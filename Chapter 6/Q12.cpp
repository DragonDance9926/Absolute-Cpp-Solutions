#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Box{
    private:
        string Contents[3];
    public:
        Box(string Contents[3]){
            this->Contents[0] = Contents[0];
            this->Contents[1] = Contents[1];
            this->Contents[2] = Contents[2];
        }
        void print(){
            cout << "Contents: " << endl;
            cout << "1. " << Contents[0] << endl;
            cout << "2. " << Contents[1] << endl;
            cout << "3. " << Contents[2] << endl;
        }
};

int main(){
    string Random[10] = {"Broccoli","Carrot","Celery","Corn","Eggplant","Garlic","Lemon","Onion","Potato","Tomato"};
    string choose3[3];
    srand(time(NULL));
    for (int i = 0; i < 3;){
        int random = rand() % 10;
        if (Random[random] != ""){
            choose3[i] = Random[random];
            Random[random] = "";
            i++;
        }
    }
    Box box(choose3);
    box.print();
    return 0;
}