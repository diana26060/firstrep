#include "StudentAfterSession2.h"
StudentAfterSession2::StudentAfterSession2(const char* _name, int _course, int _group, int _creditCardNumber,int _grades1[4],  int _grades2[5]):
StudentAfterSession1(_name, _course, _group, _creditCardNumber, _grades1){ //!!!!!
    for(int i = 0; i < 5; i++){
        grades[i] = _grades2[i];
    }
};

StudentAfterSession2::StudentAfterSession2(const StudentAfterSession2 &other) : StudentAfterSession1(other), grades{other.grades[0], other.grades[1], other.grades[2], other.grades[3], other.grades[4]}{};

StudentAfterSession2::~StudentAfterSession2(){};

int StudentAfterSession2::getGrade(int index) const{
    if(index >= 0 && index < 5){
        return grades[index];
    } else{
        return 1;
        
    }
};

void StudentAfterSession2::setGrade(int index, int grade){
    if(index >= 0 && index < 5){
       grades[index] = grade;  
    } 
};

double StudentAfterSession2::calculateAverage() const {
    double sum1 = 0;
    for(int i = 0; i < 5; i++){
        sum1 +=grades[i];
    }
    double sum = StudentAfterSession1::calculateAverage() * 4 + sum1;
    return sum / 9;
};
std::ostream& operator<<(std::ostream& out, const StudentAfterSession2 &student){
    out << "ID: " << student.getID() << std::endl;
    out << "Name: " << student.getName() << std::endl;
    out << "Course: " << student.getCourse() << std::endl;
    out << "Group: " << student.getGroup() << std::endl;
    out << "Credit card number: " << student.getCreditCardNumber() << std::endl;
    out << "Grades after 2nd session: " << std::endl;
    for(int i = 0; i < 5; i++){
        out << student.getGrade(i) << " " << std::endl;
    }
    out << "Average of grades after 2 sessions: " << student.calculateAverage();
    out << std::endl;
    return out;
};