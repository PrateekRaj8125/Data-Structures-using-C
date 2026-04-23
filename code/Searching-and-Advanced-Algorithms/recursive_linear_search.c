/*Write a C program to perform recursive linear search.*/
#include <stdio.h>

// Recursive function to perform linear search
int linearSearch(int arr[], int n, int target, int index) {
    // Base case: if index exceeds size of array, element not found
    if (index >= n) {
        return -1;
    }
    
    // If the element is found, return the index
    if (arr[index] == target) {
        return index;
    }
    
    // Recursive call: check the next element
    return linearSearch(arr, n, target, index + 1);
}

int main() {
    int n, target, result;
    
    // Read the size of the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n]; // Declare array
    
    // Read elements of the array
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read the target element to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    // Call recursive linear search function
    result = linearSearch(arr, n, target, 0);
    
    // Output the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array\n");
    
    return 0;
}
