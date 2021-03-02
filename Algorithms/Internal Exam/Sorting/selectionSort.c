#include <stdio.h>

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void selectionSort(int *array, int n) {
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++) {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[indexOfMin]) {
                indexOfMin = j;
            }
        }
        temp              = array[i];
        array[i]          = array[indexOfMin];
        array[indexOfMin] = temp;
    }
}

int main() {
    int array[] = { 12, 54, 65, 7, 23, 9 };
    int n       = sizeof(array) / sizeof(int);

    printf("\nOur array before selection sort: \n");
    printArray(array, n);

    printf("\nOur array after selection sort: \n");
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}