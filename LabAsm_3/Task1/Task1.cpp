#include <iostream>

int main() {
    int num, den, gcd;

    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denomenator: ";
    std::cin >> den;
    if (den <= 0) {
        std::cout << "Error";
        return 1;
    }

    int orig_num = num;
    int orig_den = den;

    _asm {
        mov eax, orig_num
        mov ecx, orig_den

        gcd_loop :
        test ecx, ecx
            je done

            xchg eax, ecx
            xor edx, edx
            div ecx
            mov eax, ecx
            mov ecx, edx
            jmp gcd_loop

            done :
        mov gcd, eax

    }

    num = orig_num;
    den = orig_den;

    num /= gcd;
    den /= gcd;

    std::cout << "Result: " << num << "/" << den << std::endl;

    return 0;
}
