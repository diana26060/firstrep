#ifndef STUDENTAFTERSESSION2_H
#define STUDENTAFTERSESSION2_H
#include "StudentAfterSession1.h"
class StudentAfterSession2 : public StudentAfterSession1
{
protected:
int grades[5];
public:
StudentAfterSession2(const char* _name, int _course, int _group, int _creditCardNumber,int _grades1[4], int _grades2[5]);
StudentAfterSession2(const StudentAfterSession2 &other);
StudentAfterSession2() = delete;
~StudentAfterSession2();

int getGrade(int index) const;
void setGrade(int index, int grade);

double calculateAverage() const override;
//double getAverageGrade() const override;
friend std::ostream& operator<<(std::ostream& out, const StudentAfterSession2 &student);

};

//std::ostream& operator<<(std::ostream& out, const StudentAfterSession2 &student);

#endif //STUDENTAFTERSESSION2_H