#include <iostream>
#include <cstring>
using namespace std;

bool exactMatch(char *text, char *pat)
{
 if (*text == '\0' && *pat != '\0')
  return false;
 
 // Else If last character of pattern reaches
 if (*pat == '\0')
  return true;
 
 if (*text == *pat)
  return exactMatch(text + 1, pat + 1);
 
 return false;
}
 
// This function returns true if 'text' contain 'pat'
bool contains(char *text, char *pat)
{
 // If last character of text reaches
 if (*text == '\0')
  return false;
 
 // If current characters of pat and text match
 if (*text == *pat)
  if(exactMatch(text, pat))
   return 1;
  else
  return contains(text + 1, pat);
 
 // If current characters of pat and tex don't match
 return contains(text + 1, pat);
}

int main(){
    char haystack[100];
    char needle[100];
    cout << "Enter the haystack: ";
    cin >> haystack;
    cout << "Enter the needle: ";
    cin >> needle;
    if (contains(haystack, needle)){
        cout << "The needle is in the haystack." << endl;
    }
    else{
        cout << "The needle is not in the haystack." << endl;
    }
    return 0;
}