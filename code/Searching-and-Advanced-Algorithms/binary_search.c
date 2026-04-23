/*Write a C program to perform binary search on a sorted array.*/
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow for large left, right
        
        // Check if target is at mid
        if (arr[mid] == target)
            return mid;
        
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // Target not found
    return -1;
}

int main() {
    int n, target, result;
    
    // Read the size of the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n]; // Declare array
    
    // Read elements of the array
    printf("Enter %d sorted integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read the target element to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    // Call binary search function
    result = binarySearch(arr, n, target);
    
    // Output the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array\n");
    
    return 0;
}
