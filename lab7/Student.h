
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student 
{
protected:
int id;
char* name;
int course;
int group;
int creditCardNumber;

public:
Student(const char* _name,int _course, int _group, int _creditCardNumber);
Student(const Student &other);
Student() = delete;
~Student();//деструктор

//set, get - методы
void setName(const char* _name);
const char* getName() const;
void setCourse(int _course);
int getCourse() const;
void setGroup(int _group);
int getGroup() const;
int getCreditCardNumber() const;
int getID() const;
virtual double calculateAverage() const = 0;
friend std::ostream& operator<<(std::ostream &out, const Student &student);

};
//вывод
//std::ostream& operator<<(std::ostream &out, const Student &student);

#endif //STUDENT_H