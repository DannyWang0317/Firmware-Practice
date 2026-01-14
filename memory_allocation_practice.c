#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(val, n) ((val) |= (1 << (n)))
#define CLR_BIT(val, n) ((val) &= ~(1 << (n)))
#define GET_BIT(val, n) (((val) >> (n)) & 1)
#define TOGGLE_BIT(val, n) ((val) ^= (1 << (n)))

void allocate_memory(int **p){
    *p = (int*)malloc(sizeof(int));
    **p = 100;
}

int main(){
// ------------------------------------------------
    int *ptr = NULL;
    allocate_memory(&ptr);

    printf("p = %d\n", ptr);
    printf("*p = %d\n", *ptr);
    printf("&p = %d\n", &ptr);

    free(ptr);
// ------------------------------------------------
    unsigned char reg = 0x00;
    printf("origin reg: 0x%x\n", reg);
    SET_BIT(reg, 2);
    printf("modified reg: 0x%x\n", reg);
// ------------------------------------------------
    return 0;
}