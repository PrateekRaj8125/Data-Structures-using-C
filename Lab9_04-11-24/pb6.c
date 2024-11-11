#include <stdio.h>
#include <string.h>

// Function to swap two strings
void swap(char str1[], char str2[]) {
    char temp[100]; // Temporary array to hold one string during the swap
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Function to perform bubble sort on array of strings
void sortNames(char names[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent strings
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap if they are in wrong order
                swap(names[j], names[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    
    // Read the number of names
    printf("Enter number of names: ");
    scanf("%d", &n);
    
    char names[n][100]; // Declare array to store names (each name can be 100 characters long)
    
    // Read the names from the user
    printf("Enter %d names: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    
    // Sort the names using bubble sort
    sortNames(names, n);
    
    // Print the sorted names
    printf("Names in alphabetical order: \n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    
    return 0;
}
