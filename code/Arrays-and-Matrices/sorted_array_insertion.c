/*Write a C program to insert an element into a sorted array at the correct position.*/
#include <stdio.h>

void insertSorted(int arr[], int n, int key) {
    int i;
    // Start from the last element and find the correct position for the key
    for (i = n - 1; (i >= 0 && arr[i] > key); i--) {
        arr[i + 1] = arr[i];  // Shift elements to the right
    }
    arr[i + 1] = key;  // Insert the key at the correct position
}

int main() {
    int arr[100];  // Array to hold the elements
    int n, key;

    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the new element to be inserted
    printf("Enter the element to be inserted: ");
    scanf("%d", &key);

    // Insert the new element into the sorted array
    insertSorted(arr, n, key);

    // Increment the size of the array
    n++;

    // Print the array after insertion
    printf("Array after insertion: \n");
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }

    return 0;
}
