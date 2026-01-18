// Q3
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};

struct ListStruct ListArray[1000];
#define NULL_PTR 0xFFFF
unsigned int ListHead = 0;

void foundEntry(unsigned int DATA_A, unsigned int DATA_B){
    unsigned int currentEntry = 0;
    unsigned int prevEntry = NULL_PTR;
    int isFound = 0;

    unsigned int targetValue = (DATA_A << 16) + DATA_B;

    while(currentEntry != NULL_PTR){
        unsigned int currValue = (ListArray[currentEntry].DataH << 16) + ListArray[currentEntry].DataL;
        if(currValue == targetValue){
            isFound = 1;
            printf("Found target entry: %d\n", currentEntry);
            printf("Previous entry: %d\n", prevEntry);
            break;
        }
        else if (currValue > targetValue){
            printf("Not found\n");
            break;
        }
        else{
            prevEntry = currentEntry;
            currentEntry = ListArray[currentEntry].NextPtr;
        }
    }

    if(isFound == 0){
        printf("Not found\n");
    }
}

int main() {
    // Index 0 -> Value 10, Next -> 2
    ListArray[0].DataH = 0; ListArray[0].DataL = 10; ListArray[0].NextPtr = 2;

    // Index 1 -> Value 20, Next -> 0
    ListArray[1].DataH = 0; ListArray[1].DataL = 20; ListArray[1].NextPtr = 2;

    // Index 2 -> Value 20, Next -> 0
    ListArray[2].DataH = 0; ListArray[2].DataL = 20; ListArray[2].NextPtr = 3;

    // Index 3 -> Value 50, Next -> NULL
    ListArray[3].DataH = 0; ListArray[3].DataL = 50; ListArray[3].NextPtr = NULL_PTR;

    printf("Test 1: Find 20 (Should find at index 2, pre 0)\n");
    foundEntry(0, 20);

    printf("\nTest 2: Find 50 (Should find at index 3, pre 2)\n");
    foundEntry(0, 50);

    printf("\nTest 3: Find 10 (Should find at index 0, pre NULL)\n");
    foundEntry(0, 10);

    printf("\nTest 4: Find 99 (Should not find)\n");
    foundEntry(0, 99);

    return 0;
}