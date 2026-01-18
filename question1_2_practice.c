#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void printNum1(int32_t *a, int32_t size){
    int32_t *ptr = a;
    int32_t *end = a + size;
    for(int i = 0; i < 200; i++){
        if(ptr < end && *ptr == i){
            ptr++;
        }
        else{
            printf("%d ", i);
        }
    }
}

void printNum2(int32_t *a, int32_t size, int32_t b){
    int32_t *ptr = a;
    int32_t *end = a + size;
    while(ptr < end && *ptr < b * 100){
        ptr++;
    }

    for(int i = b * 100; i < (b + 1) * 100; i++){
        if(ptr < end && *ptr == i){
            ptr++;
        }
        else{
            printf("%d ", i);
        }
    }
}

int main(){
    int32_t *array = (int*)malloc(10 * sizeof(int));
    int32_t template[] = {1, 12, 65, 75, 76, 101, 123, 156, 189, 199};
    memcpy(array, template, 10 * sizeof(int));

    printf("Array: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ", *(array + i));
    }
    printf("\n");

    printf("Q1: \n");
    printNum1(array, 10);
    printf("\n");
    printf("Q2: \n");
    printNum2(array, 10, 1);
    free(array);
    return 0;
}