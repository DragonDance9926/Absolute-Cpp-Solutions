#ifndef USER_PASSWORD_H
#define USER_PASSWORD_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace Authenticate 
{ // variable and function declarations
    void inputUserName( );
    string getUserName( );
    void inputPassword( );
    string getPassword( );
}

#endif