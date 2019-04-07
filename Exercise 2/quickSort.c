
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
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if(asc) {
            if (comparison++, arr[j] <= pivot) {
                i++;
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

        int pi = partition(arr, low, high, asc);
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