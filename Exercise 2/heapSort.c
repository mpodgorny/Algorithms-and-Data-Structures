
#include <stdio.h>
#include <time.h>
#include "heapSort.h"
#include "unifiedFunctions.h"
extern int swaps;
extern int comparison;
extern double timeUsed;
extern clock_t start, end;

//ASC ROSNĄCO asc=1 ====  ROSNOACco
void heapify(int arr[], int n, int i, int asc)
{
    int smallest = i; // root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if(asc){

        if (comparison++, l < n && arr[l] > arr[smallest])
            smallest = l;

        if (comparison++, r < n && arr[r] > arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            swaps++;

            heapify(arr, n, smallest, asc);
        }
    }else {

        if (comparison++, l < n && arr[l] < arr[smallest])
            smallest = l;

        if (comparison++, r < n && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            swaps++;

            heapify(arr, n, smallest, asc);
        }
    }
}

void heapSort(int keys[], int n, int asc)
{
    start = clock();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(keys, n, i, asc);

    for (int i = n - 1; i >= 0; i--) {

        swap(&keys[0], &keys[i]);
        swaps++;

        heapify(keys, i, 0, asc);
    }
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
}

