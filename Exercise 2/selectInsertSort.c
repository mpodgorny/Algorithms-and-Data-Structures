//
// Created by dtend on 02.04.2019.
//

#include "selectInsertSort.h"
#include <stdio.h>
#include <time.h>
#include "unifiedFunctions.h"
extern int swaps;
extern int comparison;
extern double timeUsed;
extern clock_t start, end;
//jest malejąco
void selectSort(int keys[], int n, int asc){
    start = clock();
    int minIdx;
    for (int i = 0; i < n-1; i++)
    {
        minIdx = i; //declaring current i as new minidx(temporary)
        for (int j = i+1; j < n; j++) //looking for minimum element in unsorted part of array
            if(asc){
                if(comparison++, keys[j] < keys[minIdx])
                    minIdx=j;
            } else {

                if (comparison++, keys[j] > keys[minIdx])
                    minIdx = j;
            }
        swap(&keys[minIdx], &keys[i]); //pushing new minimum value to front, exchanging places with old front value
        swaps++;
    }
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

}

void insertionSort(int keys[], int n, int asc){
    start=clock();
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = keys[i];
        swaps++;
        j = i - 1;

        if (asc) {
            while (comparison++, j >= 0 && keys[j] > key) {
                keys[j + 1] = keys[j];
                swaps++;
                j = j - 1;
            }
            keys[j + 1] = key;
            swaps++;
        } else {
        while (comparison++, j >= 0 && keys[j] < key) {
            keys[j + 1] = keys[j];
            swaps++;
            j = j - 1;
        }
        keys[j + 1] = key;
        swaps++;
        }
    }
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
}
