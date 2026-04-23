/*Write a C program to sort an array using quick sort.*/
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that places the pivot in its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of the smaller element
    
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            swap(&arr[i], &arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place the pivot at its correct position
    return (i + 1);
}

// Function that implements quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array around the pivot and get the pivot index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("Sorted array in ascending order: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
