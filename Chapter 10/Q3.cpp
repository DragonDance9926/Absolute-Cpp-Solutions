#include <cstring>
#include <iostream>

void reverse(char *head,char * tail){
    while (head < tail){
        char temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}

int main(){
    char str[] = "abcdefg";
    reverse(str,str+strlen(str)-1);
    std::cout << str << std::endl;
    return 0;
}
