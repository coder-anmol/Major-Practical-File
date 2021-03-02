// program for linear search

#include <stdio.h>

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element) {
    int low, mid, high;
    low  = 0;
    high = size - 1;
    // searching starts
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else if (arr[mid] > element) {
            high = mid - 1;
        }
    }
    // searching ends
    return -1;
}
int main() {

    int arr[]   = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size    = sizeof(arr) / sizeof(int);
    int element = 9;

    int searchIndex = linearSearch(arr, size, element);
    printf("\nThe element %d is found at index: %d using linearSearch\n", element, searchIndex);

    element = 400;
    searchIndex = binarySearch(arr, size, element);
    printf("\nThe element %d is found at index: %d using binarySearch\n", element, searchIndex);
    return 0;
}