// Lab1_Asm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
int main()
{
    //1st num
    __int16 A1 = 0x1234;
    __int16 A2 = 0x5678;
    __int16 A3 = 0x9ABC;
    //2nd num
    __int16 B1 = 0x1111;
    __int16 B2 = 0x2222;
    __int16 B3 = 0x3333;
    //3rd num - result
    __int16 C1 = 0;
    __int16 C2 = 0;
    __int16 C3 = 0;
    __asm {
        mov ax, A1
        add ax, B1
        mov C1, ax

        mov ax, A2
        add ax, B2
        mov C2, ax

        mov ax, A3
        add ax, B3
        mov C3, ax

    }
    //hex parts
    std::cout << "C1: " << std::hex << C1 << "\n";
    std::cout << "C2: " << std::hex << C2 << "\n";
    std::cout << "C3: " << std::hex << C3 << "\n";

    //dec full num
    unsigned long long fullNum = ((unsigned long long)C3 << 32) | ((unsigned long long)C2 << 16) | C1;
    std::cout << "Full Num in dec: " << std::dec << fullNum << std::endl;
    return 0;
}

