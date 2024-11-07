//#include <iostream>
#include "ProperFraction.h"
int main(){
    ProperFraction fraction1(1, 4);
    ProperFraction fraction2(-10, 30);
    ProperFraction fraction3(-9, -45);
    std::cout << fraction2.getDenominator() << std::endl;
    std::cout << fraction2.getNumerator() << std::endl;
    std::cout << fraction2.operator*(fraction3) << std::endl;
    std::cout << fraction2.operator/(fraction1) << std::endl;
    std::cout << fraction3.operator+(fraction1) << std::endl;
return 0;
}