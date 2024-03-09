#include <stdio.h>

// g++ fin-to-inf.c -O3 -o fin-to-inf

int main() {
    char buf[50] = "y";
    for (int j = 0; j < 9; j++) {
        printf("%d\n", j * 0x20000001);
        if (buf[0] == 'x') break;
    }
}

