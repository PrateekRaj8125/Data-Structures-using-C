/*Write a C program to sort an array using insertion sort.*/
#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Element to be placed at correct position
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    
    // Read the size of the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n]; // Declare array
    
    // Read elements of the array
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array using insertion sort
    insertionSort(arr, n);
    
    // Print the sorted array
    printf("Sorted array in ascending order: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
