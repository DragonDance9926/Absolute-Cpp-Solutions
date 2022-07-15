#include <iostream>
using namespace std;

class HotDogStand{
    private:
        int id;
        int Sold;
        static int TotalSold;
    public:
        HotDogStand(int id){
            this->id = id;
            Sold = 0;
        }
        static void AddTotalSold(){
            TotalSold++;
        }
        void JustSold(){
            Sold++;
            AddTotalSold();
        }
        int numSold(){
            return Sold;
        }
        static int totalSold(){
            return TotalSold;
        }
};

int HotDogStand::TotalSold = 0;



int main(){
    HotDogStand stand1(1);
    HotDogStand stand2(2);
    HotDogStand stand3(3);
    stand1.JustSold();
    stand2.JustSold();
    stand1.JustSold();
    stand3.JustSold();
    stand3.JustSold();
    cout << "Stand 1 sold " << stand1.numSold() << " hot dogs." << endl;
    cout << "Stand 2 sold " << stand2.numSold() << " hot dogs." << endl;
    cout << "Stand 3 sold " << stand3.numSold() << " hot dogs." << endl;
    cout << "Total sold: " << HotDogStand::totalSold() << endl;
    return 0;
}