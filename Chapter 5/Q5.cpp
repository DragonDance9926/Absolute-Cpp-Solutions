#include <iostream>
#include <string>
#define MAX 20
using namespace std;


string string_sum(string num1,int size1,string num2,int size2){
    int carry=0;
    int sum=0;
    string res;
    int i = size1-1,j = size2-1;
    while (i >= 0 && j >= 0){
        sum = (num1[i]-'0') + (num2[j]-'0') + carry;
        carry = sum/10;
        sum = sum%10;
        res += sum + '0';
        i--;
        j--;
    }
    while (i >= 0){
        sum = (num1[i]-'0') + carry;
        carry = sum/10;
        sum = sum%10;
        res += sum + '0';
        i--;
    }
    while (j >= 0){
        sum = (num2[j]-'0') + carry;
        carry = sum/10;
        sum = sum%10;
        res += sum + '0';
        j--;
    }
    if (carry > 0){
        res += carry + '0';
    }
    for (int i = 0; i < res.size()/2; i++){
        char temp = res[i];
        res[i] = res[res.size()-1-i];
        res[res.size()-1-i] = temp;
    }
    return res;
}

int main(){
    string num1,num2;
    size_t size1,size2;
    cout << "Enter first number: ";
    getline(cin,num1);
    size1 = num1.size();
    if (size1 > MAX){
        cout << "Number is too large" << endl;
        return 1;
    }
    cout << "Enter second number: ";
    getline(cin,num2);
    size2 = num2.size();
    if (size2 > MAX){
        cout << "Number is too large" << endl;
        return 1;
    }
    cout<<"Sum of "<<num1<<" and "<<num2<<" is "<<string_sum(num1,size1,num2,size2)<<endl;
    return 0;
}