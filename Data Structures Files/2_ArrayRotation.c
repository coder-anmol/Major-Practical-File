/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program rotates array]
 */

#include <stdio.h>
#include <stdlib.h>

// function to print array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

// function to rotate array one time
void rotateArray(int *array, int n) {
    int tempValue = array[0];
    for (int i = 0; i < (n - 1); i++) {
        array[i] = array[i + 1];
    }
    array[n - 1] = tempValue;
}

// function that rotates array with given cycles
void rotate(int *array, int d, int n) {
    for (int i = 0; i < d; i++) {
        rotateArray(array, n);
    }
}

int main() {
    int n, d;
    int *array;

    printf("\nEnter the size of array: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("\nEnter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("\nElements in the array are: \n");
    printArray(array, n); // prints all elements of array

    printf("\nEnter Rotation: ");
    scanf("%d", &d);

    rotate(array, d, n); // rotates array by d size

    printf("\nArray after rotation: \n");
    printArray(array, n);

    return 0;
}
