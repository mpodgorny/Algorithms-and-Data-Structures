
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unifiedFunctions.h"
extern int swaps;
extern int comparison;
extern double timeUsed;
extern clock_t start, end;

int testSorted(int keys[], int n, int asc) {
    for (int i = 1; i < n; i++) {
        if (asc) { //ascending *rosnąco*
            if (keys[i - 1] > keys[i]){
                return 0;
            }
        } else
            if (keys[i - 1] < keys[i]) {
                return 0;
            }
    }
    return 1;
}

void printArray(int keys[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf(" %d ;", keys[i]);
    printf("\n");
}
void swap(int *newMin, int *oldFirst)
{
    int temp = *newMin;
    *newMin = *oldFirst;
    *oldFirst = temp;
}
