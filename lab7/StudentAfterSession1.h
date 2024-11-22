#ifndef STUDENTAFTERSESSION1_H
#define STUDENTAFTERSESSION1_H
#include "Student.h"

class StudentAfterSession1 : public Student
{
protected:
int grades[4];
public:
StudentAfterSession1(const char* _name,int _course, int _group, int _creditCardNumber, int _grades[4]);
StudentAfterSession1(const StudentAfterSession1 &other);
StudentAfterSession1() = delete;
~StudentAfterSession1();

int getGrade(int index) const;
void setGrade(int index, int grade);

double calculateAverage() const override;
//virtual double getAverageGrade() const;
friend std::ostream& operator<<(std::ostream& out, const StudentAfterSession1 &student);

};


#endif //STUDENTAFTERSESSION1_H