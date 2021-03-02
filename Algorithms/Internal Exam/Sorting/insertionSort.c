// intermediate result of insertion sort is not useful
#include <stdio.h>

void insertionSort(int *, int);
void printArray(int *, int);

void insertionSort(int *array, int n) {
    // loop for pass
    int key;
    int j;

    for (int i = 1; i <= n - 1; i++) {    // loop for each pass
        key = array[i];                   // element selected
        j   = i - 1;                      // index of element to compare with

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];    // assigning the greatest value of sub array to index i
            j--;
        }

        array[j + 1] = key;    // setting a key at its place

        // for dry run purpose
        printf("\nArray at pass: %d\n", i);
        printArray(array, n);
    }
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 12, 54, 65, 7, 23, 9 };
    int n       = sizeof(array) / sizeof(int);

    printf("\nOur array before insertion sort: \n");
    printArray(array, n);

    printf("\nOur array after insertion sort: \n");
    insertionSort(array, n);
    printArray(array, n);
    // right side se ek ek element pkad pkad ke insert ho rahe he left side pr: isliye is algo ko insertion sort bola jata hai
    return 0;
}


