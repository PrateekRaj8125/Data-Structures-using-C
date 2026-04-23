/*Write a C program to find the maximum and minimum elements in an array using recursion.*/
#include <stdio.h>

// Function to find the maximum element in an array recursively
int findMax(int arr[], int n) {
    // Base case: If the array has only one element
    if (n == 1) {
        return arr[0];
    }

    // Recursive call to find the maximum of the remaining array
    int max = findMax(arr, n - 1);

    // Compare the last element with the maximum of the remaining array
    if (arr[n - 1] > max) {
        return arr[n - 1];
    } else {
        return max;
    }
}

// Function to find the minimum element in an array recursively
int findMin(int arr[], int n) {
    // Base case: If the array has only one element
    if (n == 1) {
        return arr[0];
    }

    // Recursive call to find the minimum of the remaining array
    int min = findMin(arr, n - 1);

    // Compare the last element with the minimum of the remaining array
    if (arr[n - 1] < min) {
        return arr[n - 1];
    } else {
        return min;
    }
}

int main() {
    int arr[] = {5, 8, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, n);
    int min = findMin(arr, n);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}
