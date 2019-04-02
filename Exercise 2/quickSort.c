//
// Created by dtend on 01.04.2019.
//

#include <time.h>
#include "quickSort.h"
#include "unifiedFunctions.h"

//jest ASCENDING
extern int swaps;
extern int comparison;
extern double timeUsed;
extern clock_t start, end;

int partition (int arr[], int low, int high, int asc)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if(asc) {
            if (comparison++, arr[j] <= pivot) {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
                swaps++;
            }
        }else if (comparison++, arr[j] >= pivot){
            i++;
            swap(&arr[i], &arr[j]);
            swaps++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swaps++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int asc) {

    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high, asc);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, asc);
        quickSort(arr, pi + 1, high, asc);
    }
}

void initQuickSort(int keys[], int n, int asc){
    start = clock();
    int high=n-1;
    quickSort(keys, 0, high, asc);
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
}