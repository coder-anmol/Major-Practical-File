/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [Program to code basic array]
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array, arraySize;

    // array size taken
    printf("\nEnter the size of the array: ");
    scanf("%d", &arraySize);

    // allocated memory in heap
    array = (int *)malloc(arraySize * sizeof(int));

    // taking elements input
    printf("\nEnter the elements in the array: ");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    // showing output of elements in array
    printf("\nElements of the array are: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}