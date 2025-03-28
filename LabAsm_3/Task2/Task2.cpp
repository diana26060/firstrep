#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int x, y;

    __asm {
        mov count, 0
        mov x, 1

        start_x:
            mov y, 1

        start_y :
            mov eax, 2
            imul eax, x
            mov ebx, 3
            imul ebx, y
            add eax, ebx
            cmp eax, 50
            je found
            jmp next_y

        found :
            inc count

        next_y :
            inc y
            cmp y, 50
            jl start_y

        next_x :
            inc x
            cmp x, 50
            jl start_x
    }

    cout << "Amount of solutions: " << count << endl;

    for (x = 1; x < 50; x++) {
        for (y = 1; y < 50; y++) {
            if (2 * x + 3 * y == 50) {
                cout << "2*" << x << " + 3*" << y << " = 50" << endl;
            }
        }
    }
    return 0;
}
