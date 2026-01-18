#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void change(int *a, int *b, int c) {
        c = *a;
        *b = 3;
        *a = 2;
}

int main() {
        int a = 1, b = 2, c = 3;
        change(&a, &b, c);
        printf("%d %d %d\n", a, b, c);

        int32_t volatile * const ptr = (int*) 0x1234;
        *ptr = 0xaa55;
        printf("ptr: %d", ptr);
        printf("value: %d", *ptr);

        return 0;
}