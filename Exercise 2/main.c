#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"
#include "unifiedFunctions.h"
#include "heapSort.h"
#include "selectInsertSort.h"
#include "rngGood.h"
/* Function to print an array */

/*
 * ASC [ascending] ROSNĄCO
 * DESC [descending] MALEJĄCO
 * 1 TRUE 0 FALSE
 */

//  ./main --type quick --desc 4 wartosci!
//fprintf( stderr, "my %s has %d chars\n", "string format", 30);


int swaps=0;
int comparison=0;
double timeUsed=0;
clock_t start, end;
FILE *out_file;

void openFile(char* file){
    printf("opening %s\n", file);
    out_file = fopen(file, "w"); // write + read. Oversaving
    if (out_file == NULL){
        printf("Error! Could not open file\n");
        exit(-1);
    }
    fprintf(out_file, "name, nr_of_swaps, nr_of_comparison, time_seconds");
    printf("File opened. Calculating...\n");
}

//name, nr_of_swaps, nr_of_comparison, time_seconds
void saveAndReset(char* sort, int n){
    fprintf(out_file, "%s, %d, %d, %d, %f\n",sort,n, swaps, comparison, timeUsed);
    swaps=0;
    comparison=0;
    timeUsed=0;
    start=0;
    end=0;
}


void getInput(void (*fun)(int[], int, int), int asc){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    fun(arr, n, asc);
    fprintf(stderr, "Swaps: %d, comparisons: %d. time taken: %f seconds\n",swaps, comparison, timeUsed);
    if(testSorted(arr,n,asc)) {
        printf("[elements: %d]\n", n);
        printArray(arr, n);
    }else
        printf("Array not sorted!");
}

void copyArray(int original[], int copy[], int n){
    for (int i = 0; i< n ; i++){
        copy[i]=original[i];
    }
}

//comparator
void getRandomInput(int k){
    //n in 100, 200, 300 ... 10000[10k]
    struct cmwc_state cmwc;
    unsigned int seed = time(NULL);
    initCMWC(&cmwc, seed);
    for(int i = 100; i<=10000;i+=100) {
        for(int p=0;p<k;p++) {
            int arr[i];
            for (int j = 0; j < i; j++) {
                arr[j] = randCMWC(&cmwc);
            }//after this arr cotains rn. We should now loop through all sorting functions.
            int n=sizeof(arr)/sizeof(arr[0]);
            int tempArray[n];
            copyArray(arr, tempArray, n);
            selectSort(tempArray, n, 1);

            saveAndReset("selectSort", n);
            copyArray(arr, tempArray, n);
            insertionSort(tempArray, n, 1);

            saveAndReset("insertionSort", n);
            copyArray(arr, tempArray, n);
            heapSort(tempArray, n, 1);

            saveAndReset("heapSort", n);
            copyArray(arr, tempArray, n);
            initQuickSort(tempArray, n, 1);

            saveAndReset("quickSort", n);
        }

    }
}

void getFlags(int argc, char *argv[]){
    int asc;
    if (argc!=4 && argc!=7){
        printf("4 or 7 arguments only! Use --type select|insert|heap|quick --desc|asc");
        exit(1);
    }

    if(strcmp(argv[3],"--asc")==0){
        asc=1;

    } else if(strcmp(argv[3],"--desc")==0){
        asc=0;
    }
    else {
        printf("Not valid flag. Use --asc|desc");
    }
    if (argc==7 && strcmp(argv[4], "--stat") == 0) {
        openFile(argv[5]);
        getRandomInput(atoi(argv[6]));  // [0]main.c [1]--type [2]select|insert|.. [3]--asc|desc [4]--stat [5]--filename [6]par_k
        printf("Calculation completed. Closing file...\n");
        fclose(out_file);
    } else{
        if(strcmp(argv[1], "--type")==0) {
            if (strcmp(argv[2], "select")==0) {
                getInput(&selectSort, asc);
            } else if (strcmp(argv[2], "insert")==0) {
                getInput(&insertionSort, asc);
            } else if (strcmp(argv[2], "heap")==0) {
                getInput(&heapSort, asc);
            } else if (strcmp(argv[2], "quick")==0) {
                getInput(&initQuickSort,asc);
            } else {
                printf("Wrong parameter after --type flag!");
                exit(1);
            }
        } else {
            printf("Wrong flag! use --type");
            exit(1);
        }
    }
    }

int main (int argc, char *argv[]){
    getFlags(argc, argv);
}

