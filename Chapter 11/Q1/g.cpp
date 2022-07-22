#include <iostream>
#include "g.hpp"

namespace A{
    void g(){
        std::cout << "Function g() in namespace A" << std::endl;
    }
}
void g(){
    std::cout << "Function g() in global namespace" << std::endl;
}