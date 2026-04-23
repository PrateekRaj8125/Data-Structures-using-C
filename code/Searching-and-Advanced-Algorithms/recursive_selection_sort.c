/*Write a C program to perform selection sort using recursion.*/
#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to recursively perform selection sort
void recursiveSelectionSort(int arr[], int n, int index) {
    // Base case: if index is the last element, return (array is sorted)
    if (index == n - 1) {
        return;
    }

    // Find the minimum element in the unsorted portion of the array
    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the found minimum element with the first element of the unsorted portion
    if (minIndex != index) {
        swap(&arr[minIndex], &arr[index]);
    }

    // Recursively sort the remaining part of the array
    recursiveSelectionSort(arr, n, index + 1);
}

int main() {
    int n;

    // Read the number of elements in the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array

    // Read elements of the array
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the recursive selection sort function
    recursiveSelectionSort(arr, n, 0);

    // Print the sorted array
    printf("Sorted array in ascending order: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
