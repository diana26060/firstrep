#include "Student.h"
#include "StudentAfterSession1.h"
#include "StudentAfterSession2.h"
#include <vector>


int main(){
    int grades1[] = {3,4,5,2};
    int grades2[] = {4,4,2,5,5};
    int grades3[] = {3,4,4,2};
    int grades4[] = {4,4,3,5,5};
    int grades5[] = {3,4,5,3};
    int grades6[] = {5,4,2,3,5};

     StudentAfterSession2 student1("Bob", 1, 3, 2233, grades1, grades2);
     StudentAfterSession2 student2("Ann", 1, 2, 123123, grades3, grades4);
     std::cout << student1;
     std::cout << student2;

     std::cout << "--------------------------------------------------------------" << std::endl;


  //tasks 4, 5
    Student* students[3];
    students[0] = new StudentAfterSession1("Alice", 1, 2, 55123, grades1);
    students[1] = new StudentAfterSession2("Ryan", 1, 2, 2243, grades3, grades4);
    students[2] = new StudentAfterSession2("Mary", 1, 2, 9903, grades5, grades6);
    

    double totalAverage = 0;
    for(int i = 0; i < 3; i++){
      std::cout << *students[i] << std::endl;
      totalAverage += students[i]->calculateAverage();
      delete students[i];
    }
std::cout << "Average grade of group: " << totalAverage / 3 << std::endl;
   return 0;
}