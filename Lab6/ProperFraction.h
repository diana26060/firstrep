#pragma once
#include <iostream> 

class ProperFraction
{
private:
    int numerator;
    int denominator;
    void simplification(); //метод для сокращения
public:
    //ProperFraction() = default;

    ProperFraction(int _numerator, int _denominator);

    ProperFraction(const ProperFraction &other); // конструктор копирования
    ProperFraction() = delete;
    // get-методы
    int getNumerator() const;
    int getDenominator() const;

    // методы арифметических действий
    ProperFraction operator+(const ProperFraction &other);
    ProperFraction operator*(const ProperFraction &other);
    ProperFraction operator/(const ProperFraction &other);
};
//вывод дроби
std::ostream& operator<<(std::ostream &out, const ProperFraction &fraction);