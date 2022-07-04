#include <iostream>
#include <cstdlib>

typedef struct person{
    bool is_alive;
    int shoot_chance;
    int order;
    int win;
}person;

person create_person(int chance,int order){
    person p;
    p.is_alive = true;
    p.shoot_chance = chance;
    p.order = order;
    p.win = 0;
    return p;
}


bool kill(person *killer,person *victim){
    int random = rand() % 101;
    if(random < killer->shoot_chance){
        victim->is_alive = false;
        return true;
    }
    return false;
}

bool turn(person *killer,person *victim1,person *victim2){
    int random = rand() % 2;
    switch (random)
    {
    case 0:
        if (victim1->is_alive)
            return kill(killer,victim1);
        else
            return false;
    case 1:
        if (victim2->is_alive)
            return kill(killer,victim2);
        else
            return false;
    default:
        return false;
    }
}


int main(){
    srand(time(NULL));
    person aaron = create_person(33,1);
    person bob = create_person(50,2);
    person carl = create_person(100,3);
    int person = 3;
    for(int i = 0;i < 10000;i++){
        while (true){
        if (turn(&aaron,&bob,&carl))
            person--;
        if (person == 1)
            break;
        if (turn(&bob,&carl,&aaron))
            person--;
        if (person == 1)
            break;
        if (turn(&carl,&aaron,&bob))
            person--;
        if (person == 1)
            break;
        }
        if (aaron.is_alive)
            aaron.win++;
        if (bob.is_alive)
            bob.win++;
        if (carl.is_alive)
            carl.win++;
        aaron.is_alive = true;
        bob.is_alive = true;
        carl.is_alive = true;
        person = 3;
    }
    std::cout << "Aaron won " << aaron.win * 100.0 / 10000 << "% of the time" << std::endl;
    std::cout << "Bob won " << bob.win * 100.0 / 10000 << "% of the time" << std::endl;
    std::cout << "Carl won " << carl.win * 100.0 / 10000 << "% of the time" << std::endl;
    return 0;
}

