// #include <stdbool.h>
#include <stdio.h>
// bubble sort

void bubbleSort(int *array, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++)    // for no of passes
    {
        for (int j = 0; j < n - 1 - i; j++) {    // for comparison in each pass
            if (array[j] > array[j + 1]) {
                temp         = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *array, int n) {
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)    // for no of passes
    {
        isSorted = 1;

        printf("Working on pass no: %d\n", i + 1);

        for (int j = 0; j < n - 1 - i; j++) {    // for comparison in each pass
            if (array[j] > array[j + 1]) {
                temp         = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = temp;
                isSorted     = 0;
            }
        }
        if (isSorted) {
            return;
        }
    }
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 1,2,3,4,5};
    int size    = sizeof(array) / sizeof(int);

    printf("\nArray before bubble sorting: \n");
    printArray(array, size);

    printf("\nArray after bubble sorting: \n");
    bubbleSortAdaptive(array, size);
    printArray(array, size);

    return 0;
}