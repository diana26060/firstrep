#include <iostream>
// (2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x)

int main()
{
    int x, x1;
    std::cout << "Enter x for asm: " << '\n';
    std::cin  >> x;
    std::cout << "Enter x for c++: " << '\n';
    std::cin >> x1;
    _asm {
        mov eax, x
        imul eax, 2
        sub eax, 1
        mov ebx, x
        imul ebx,2
        add ebx,1
        imul eax,ebx
       
        mov ecx,x
        add ecx,3
        imul eax,ecx
        
        
        mov ebx, x
        imul ebx, 2
        mov edx, 0
        idiv ebx
        mov x, eax
        
            }
    x1 = ((2 * x1) - 1)*(2 * x1 + 1)* (x1 + 3) / (2 * x1);
    std::cout << "ASM: " << x << '\n';
    std::cout << "C++:" << x1;
}
