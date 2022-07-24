#include <iostream>
#include <cstring>
using namespace std;

bool isMoney( const char*, size_t );
bool state0( const char*, size_t );
bool state1( const char*, size_t );
bool state2( const char*, size_t );
bool state3( const char*, size_t );
bool state4( const char*, size_t );
bool state5( const char*, size_t );
bool state6( const char*, size_t );
bool state7( const char*, size_t );

int main(){
    char text[100];
    cout << "Enter the text: ";
    cin >> text;
    if (isMoney(text,0)){
        cout << "The text is a money amount." << endl;
    }
    else{
        cout << "The text is not a money amount." << endl;
    }
    return 0;
}


bool isMoney( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c == '$' )
        return state0( cstr, i+1 );
    return false;
}
// first char after $ must be 1-9
bool state0( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '1' && c <= '9' )
        return state1( cstr, i+1 );
    return false;
}

// char after 1 digit must be 0-9 or , or end
bool state1( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c >= '0' && c <= '9' )
        return state2( cstr, i+1 );
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// char after 2 digits must be 0-9 or , or end
bool state2( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c >= '0' && c <= '9' )
        return state3( cstr, i+1 );
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// char after 3 digits must be , or end
bool state3( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// 1st char after , must be 0-9
bool state4( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state5( cstr, i+1 );
    return false;
}

// 2nd char after , must be 0-9
bool state5( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state6( cstr, i+1 );
    return false;
}

// 3rd char after , must be 0-9
bool state6( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state7( cstr, i+1 );
    return false;
}

// after , and 3 digits, must be another digit or end
bool state7( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}
