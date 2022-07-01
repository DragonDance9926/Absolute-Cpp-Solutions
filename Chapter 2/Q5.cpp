
/*
Find solution for:
TOO + TOO + TOO + TOO = GOOD
*/
#include <iostream>
using namespace std;

int main(){
    long long G,T,O,D;
    long long too,good;
    for(T = 0;G < 10;G++){
        for(O = 0;T < 10;T++){
            for(D = 0;O < 10;O++){
                /*
                G*1000 + O *110 + D = T*400 + 44*O
                G*1000 = T*400 - 66*O - D
                G = (T*400-66*O-D)/1000
                */
                long long too = T*100 + O*10 + O;
                G = (T*400 -66*O - D) / 1000;
                if (G >= 0 && G < 10){
                    cout << "G = " << G << " T = " << T << " O = " << O << " D = " << D << "\n";
                }
            }
        }
    }
    return 0;
    
}