#include <iostream>
#include <fstream>
#include <string>
#include <vector>
typedef struct person{
    int score;
    std::string name;
}person;
person find_max(std::vector <person> &v){
    person max = v[0];
    for (auto i : v){
        if (i.score > max.score)
            max = i;
    }
    return max;
}

int main(){
    std::vector <person> people;
    person p;
    std::fstream file;
    file.open("scores.txt",std::ios::in);
    while(file >> p.name >> p.score){
        people.push_back(p);
    }
    file.close();
    person max = find_max(people);
    std::cout << "The highest score is " << max.score << " by " << max.name << "\n";
}
