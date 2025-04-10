#include <iostream>
#include <iomanip>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int n;
    std::cout << "Enter the number of iterations (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Error: Number of iterations must be > 0\n";
        return 1;
    }

    double sum = 0.0;
    double one = 1.0;
    int denominator;

    __asm {
        finit;
        fldz;
        mov ecx, 1;

    loop_start:
        cmp ecx, n;
        jg loop_end;

        mov eax, ecx
            shl eax, 1;
        dec eax;
        mov denominator, eax;

        fild denominator;
        fmul st(0), st(0);

        fld one;
        fdiv st(0), st(1);

        fadd st(2), st(0);

        fstp st(0);
        fstp st(0);

        inc ecx;
        jmp loop_start;

    loop_end:
        fstp sum;
    }

    double result = sum;
    double pi_squared_over_8 = (M_PI * M_PI) / 8.0;

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Computed sum:         " << result << "\n";
    std::cout << "Expected (π² / 8):    " << pi_squared_over_8 << "\n";
    std::cout << "Difference:       " << std::abs(result - pi_squared_over_8) << "\n";

    return 0;
}
