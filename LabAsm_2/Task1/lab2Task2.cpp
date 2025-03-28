#include <iostream>

int main()
{
    int n, orig, square, divisor, result;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Num is less than 0 :(";
        return 0;
    }

    orig = n;

    _asm {
        mov eax, n
        imul eax, n
        mov square, eax

        mov ecx, n
        mov divisor, 1

        div_loop:
        cmp ecx, 0
            je loop_end
            mov eax, divisor
            imul eax, 10
            mov divisor, eax

            mov eax, ecx
            xor edx, edx
            mov ebx, 10
            div ebx
            mov ecx, eax
            jmp div_loop

            loop_end :
        mov eax, square
            xor edx, edx
            mov ebx, divisor
            div ebx

            cmp edx, orig
            jne set_not_auto
            mov result, 1
            jmp finish

            set_not_auto :
        mov result, 0

            finish :
    }

    if (result)
        std::cout << "n is automorphic";
    else
        std::cout << "n is not automorphic";
    return 0;
}
