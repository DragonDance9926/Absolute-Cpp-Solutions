#include <iostream>

class notes{
    double midterm;
    double final;
    double quiz1;
    double quiz2;
    char grade;
    public:
        void set_midterm(double);
        void set_final(double);
        void set_quiz1(double);
        void set_quiz2(double);
        void set_grade();
        double get_midterm();
        double get_final();
        double get_quiz1();
        double get_quiz2();
        char get_grade();
};

int main(){
    double midterm, final, quiz1, quiz2;
    std::cout << "Enter the midterm, final, quiz1, and quiz2 grades: ";
    std::cin >> midterm >> final >> quiz1 >> quiz2;
    notes grade;
    grade.set_midterm(midterm);
    grade.set_final(final);
    grade.set_quiz1(quiz1);
    grade.set_quiz2(quiz2);
    grade.set_grade();
    std::cout << "The grade is " << grade.get_grade() << std::endl;
    return 0;
}



void notes::set_midterm(double m){
    midterm = m;
}
void notes::set_final(double f){
    final = f;
}
void notes::set_quiz1(double q1){
    quiz1 = q1;
}
void notes::set_quiz2(double q2){
    quiz2 = q2;
}
void notes::set_grade(){
    double total = midterm * 0.25 + final * 0.5 + (quiz1 + quiz2) * 0.25;
    if(total >= 90){
        grade = 'A';
    }
    else if(total >= 80){
        grade = 'B';
    }
    else if(total >= 70){
        grade = 'C';
    }
    else if(total >= 60){
        grade = 'D';
    }
    else{
        grade = 'F';
    }
}

double notes::get_midterm(){
    return midterm;
}
double notes::get_final(){
    return final;
}
double notes::get_quiz1(){
    return quiz1;
}
double notes::get_quiz2(){
    return quiz2;
}
char notes::get_grade(){
    return grade;
}