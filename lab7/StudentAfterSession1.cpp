#include "StudentAfterSession1.h"

StudentAfterSession1::StudentAfterSession1(const char* _name,int _course, int _group, int _creditCardNumber, int _grades[4]):
Student(_name, _course, _group, _creditCardNumber){
    for(int i = 0; i < 4; i++){
        grades[i] = _grades[i];
    }
};

StudentAfterSession1::StudentAfterSession1(const StudentAfterSession1 &other):
Student(other){
    for(int i = 0; i < 4; i++){
        grades[i] = other.grades[i];
    }
}
StudentAfterSession1::~StudentAfterSession1(){};

int StudentAfterSession1::getGrade(int index) const{
    if(index >=0 && index < 4){
        return grades[index];
    } else {
        return 1;
    }
};

void StudentAfterSession1::setGrade(int index, int grade){
    if(index >= 0 && index < 4){
        grades[index] = grade;
    } 
};

double StudentAfterSession1::calculateAverage() const{
    double sum = 0;
    for(int i = 0; i < 4; i++){
        sum +=grades[i];
    }
    return sum/4;
};

std::ostream& operator<<(std::ostream& out, const StudentAfterSession1 &student){
    out << "ID: " << student.getID() << std::endl;
    out << "Name: " << student.getName() << std::endl;
    out << "Course: " << student.getCourse() << std::endl;
    out << "Group: " << student.getGroup() << std::endl;
    out << "Credit card number: " << student.getCreditCardNumber() << std::endl;
    out << "Grades after 1st session: ";
    for(int i = 0; i < 4; i++){
        out << student.getGrade(i) << " " << std::endl;
    }
    out << std::endl;
    return out;
}