#include "ProperFraction.h"
#include <iostream>
   ProperFraction::ProperFraction(int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
        if(denominator == 0){
            std::cout << "Denominator cant be 0. Type another one" << std::endl;

        } 
        simplification();
    };

    ProperFraction::ProperFraction(const ProperFraction &other){
        numerator = other.numerator;
        denominator = other.denominator;
    };
    
    int ProperFraction::getNumerator() const {
        return numerator;
    };

    int ProperFraction::getDenominator() const {
        return denominator;
    };
   void ProperFraction::simplification(){
        if(numerator != 0){
            int temp;
            if(abs(numerator) >= abs(denominator)){
                temp = abs(numerator);
            }
            else if(abs(numerator) < abs(denominator)){
                temp = abs(denominator); 
            } 
            for (int i = temp; i > 0; i--){
                if(numerator % i == 0 && denominator % i == 0){
                    numerator /= i;
                    denominator /= i;
                }
            }
        }
        std::cout << "simlified" << std::endl;
    };
    ProperFraction ProperFraction::operator+(const ProperFraction &other){ 
        int newNumerator = numerator * other.denominator +denominator*other.numerator;
        int newDenominator  = denominator*other.denominator;
        return ProperFraction(newNumerator, newDenominator);
    };
    ProperFraction ProperFraction::operator*(const ProperFraction &other){
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return ProperFraction(newNumerator, newDenominator);
    };
    ProperFraction ProperFraction::operator/(const ProperFraction &other){
         if(other.numerator == 0){
            std::cout << "Division by 0 is not possible."<< std::endl;
            return *this;
    }
   
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return ProperFraction(newNumerator, newDenominator);
    }; 

    std::ostream& operator<<(std::ostream& out, const ProperFraction &fraction) {
    if (fraction.getNumerator() == 0) {
        out << "0"; 
        return out;
    }
    if(abs(fraction.getNumerator()) > abs(fraction.getDenominator())){
        int integerPart = abs(fraction.getNumerator()) / abs(fraction.getDenominator());
        int newNumerator = abs(fraction.getNumerator()) - abs(fraction.getDenominator()) * integerPart;
        if(fraction.getNumerator() < 0){
            out<< "-(" << integerPart << " and " << newNumerator << "/" << fraction.getDenominator()<< ")" << std::endl;
        } else if(fraction.getDenominator() < 0){
            out<< "-(" << integerPart << " and " << newNumerator << "/" << abs(fraction.getDenominator()) << ")" << std::endl;
        }
    } else if (fraction.getNumerator() < 0 && fraction.getDenominator() < 0) {
        out << abs(fraction.getNumerator()) << "/" << abs(fraction.getDenominator()); 
    } else if (fraction.getNumerator() < 0) {
        out << "-(" << abs(fraction.getNumerator()) << "/" << fraction.getDenominator() << ")";
    } else if(fraction.getDenominator() < 0){
        out << "-(" << fraction.getNumerator() << "/" << abs(fraction.getDenominator()) << ")";
    } else {
        out << fraction.getNumerator() << "/" << fraction.getDenominator();
    }
    return out;
}

    