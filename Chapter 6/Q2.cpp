#include <iostream>

class counter{
    private:
        int count;
    public:
        void set_count(){
            count = 0;
        }
        void increment(){
            count++;
        }
        void decrement(){
            count--;
            if (count < 0){
                count = 0;
            }
        }
        int get_count(){
            return count;
        }
};


int main(){
    counter c;
    c.set_count();
    bool matchres[10] = {true,true,true,false,true,false,true,false,true,false};
    for (int i = 0; i < 10; i++){
        if (matchres[i]){
            c.increment();
        }
        else{
            c.decrement();
        }
        std::cout << c.get_count() << std::endl;
    }
    return 0;
}