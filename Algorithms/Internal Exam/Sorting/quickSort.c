#include <stdio.h>

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int partition(int *array, int low, int high) {
    int pivot = array[low];
    int i     = low + 1;
    int j     = high;
    int temp;

    do {
        while (array[i] <= pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp     = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

    } while (i < j);

    temp       = array[low];
    array[low] = array[j];
    array[j]   = temp;

    return j;
}
void quickSort(int *array, int low, int high) {
    int partitionIndex;    // index of pivot after partition

    if (low < high) {
        partitionIndex = partition(array, low, high);
        printArray(array, 10);
        printf("\npartition index: %d\n", partitionIndex);
        quickSort(array, low, partitionIndex - 1);       // sorts left sub array
        quickSort(array, partitionIndex + 1, high);      // sorts right sub array
    }
}

int main() {
    int array[] = { 4, 1, 8, 9, 2 ,3,9,14,12,10};
    int n       = sizeof(array) / sizeof(int);

    printf("\nOur array before quick sort: \n");
    printArray(array, n);

    printf("\nOur array after quick sort: \n");
    quickSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}
