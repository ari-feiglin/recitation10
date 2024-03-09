#include <stdio.h>

// clang danger.c -O3 -o danger

typedef int (*Function) ();

static int (*Do)();

static int danger() {
    printf("Danger\n");
    return 0;
}

void NeverCalled() {
    Do = danger;
}

int main() {
    Do();
}

