//
// Created by dtend on 02.04.2019.
//

#include <stdio.h>
#include <time.h>
#include "heapSort.h"
#include "unifiedFunctions.h"
//TODO: uporządkować kod, pobrać once more z geekow i zaimplementować desc i asc
extern int swaps;
extern int comparison;
extern double timeUsed;
extern clock_t start, end;

//ASC ROSNĄCO asc=1 ====  ROSNOACco
void heapify(int arr[], int n, int i, int asc)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if(asc){
// If left child is larger than root
        if (comparison++, l < n && arr[l] > arr[smallest])
            smallest = l;

        // If right child is larger than largest so far
        if (comparison++, r < n && arr[r] > arr[smallest])
            smallest = r;

        // If largest is not root
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            swaps++;
            // Recursively heapify the affected sub-tree
            heapify(arr, n, smallest, asc);
        }
    }else {
        // If left child is smaller than root
        if (comparison++, l < n && arr[l] < arr[smallest])
            smallest = l;

        // If right child is smaller than smallest so far
        if (comparison++, r < n && arr[r] < arr[smallest])
            smallest = r;

        // If smallest is not root
        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            swaps++;
            // Recursively heapify the affected sub-tree
            heapify(arr, n, smallest, asc);
        }
    }
}

// main function to do heap sort
void heapSort(int keys[], int n, int asc)
{
    start = clock();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(keys, n, i, asc);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&keys[0], &keys[i]);
        swaps++;

        // call max heapify on the reduced heap
        heapify(keys, i, 0, asc);
    }
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
}

