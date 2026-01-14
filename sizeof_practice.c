#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define Size 20
size_t getintSize(const int *ptr);
size_t getfloatSize(const float *ptr);

int main(){

    // int array_1[Size];
    int *array_1 = (int*)malloc(Size * sizeof(int));
    printf("Memory address is %zu (int)\n", array_1);
    printf("Number of bytes in the array is %zu (int)\n", sizeof(array_1));
    printf("Number of bytes returned by getSize is %zu (int)\n", getintSize(array_1));

    float array_2[Size];
    printf("Memory address is %zu (float)\n", array_2);
    printf("Number of bytes in the array is %zu (float)\n", sizeof(array_2));
    printf("Number of bytes returned by getSize is %zu (float)\n", getfloatSize(array_2));

    return 0;
}

size_t getintSize(const int *ptr){
    return sizeof(ptr);
}

size_t getfloatSize(const float *ptr){
    return sizeof(ptr);
}