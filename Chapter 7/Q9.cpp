#include <iostream>
#include <string>
#include <vector>
using namespace std;

class zip_code{
    private:
        string zip;
        int zipcode;
        void calculate_zip_code();
        void calculatezip();
        string parsenum(int);
        int calculate_part(string);
    public:
        zip_code(int);
        zip_code(string zip);
        int get_zip_code();
        string get_zip();
};


string zip_code::parsenum(int num){
    string num_str = "";
    if (num == 0){
        return "11000";
    }
    else{
        int count_ones = 0;
        auto addnum = [&num_str,&num,&count_ones](int limit){
            if (num >= limit && count_ones < 2){
                num_str += "1";
                num -= limit;
                count_ones++;
            }
            else{
                num_str += "0";
            }
        };
        addnum(7);
        addnum(4);
        addnum(2);
        addnum(1);
        addnum(0);
        return num_str;
    }
}


void zip_code::calculatezip(){
    vector <string> zip_parts;
    zip += "1";
    int temp = zipcode;
    while (temp > 0){
        zip_parts.push_back(parsenum(temp % 10));
        temp /= 10;
    }
    for (int i = zip_parts.size() - 1; i >= 0; i--){
        zip += zip_parts[i];
        //cout << zip_parts[i] << endl;
    }
    zip += "1";
}


int zip_code::calculate_part(string zip){
    int pattern[5] = {7,4,2,1,0};
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += (zip[i] - '0') * pattern[i];
    }
    return sum;
}

void zip_code::calculate_zip_code(){
    //split the zip code into five parts
    //take the string except first and last character
    string buffer = zip.substr(1,zip.length()-2);
    //calculate the sum of the five parts
    int sum = 0;
    for(int i = 0; i < 25; i += 5){
        //cout << buffer.substr(i,5) << endl;
        sum *= 10;
        int buffer_sum = calculate_part(buffer.substr(i,5));
        sum += buffer_sum == 11 ? 0 : buffer_sum;
    }
    zipcode = sum;
}

zip_code::zip_code(int zipcode){
    this->zipcode = zipcode;
    calculatezip();
}

zip_code::zip_code(string zip){
    this->zip = zip;
    calculate_zip_code();
}
int zip_code::get_zip_code(){
    return zipcode;
}
string zip_code::get_zip(){
    return zip;
}

int main(){
    zip_code zip(99504);
    cout << zip.get_zip_code() << endl;
    cout << zip.get_zip() << endl;
    return 0;
}