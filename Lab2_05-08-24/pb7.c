//7. Write a program to pass a structure as the parameter of the function by value.
#include <stdio.h>

// Define a structure named 'Point'
struct Point {
    int x;
    int y;
};

// Function that takes a structure of type 'Point' as a parameter (by value)
void printPoint(struct Point p) {
    // Print the values of the structure members
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}

int main() {
    // Declare and initialize a structure variable
    struct Point p1 = {10, 20};
    
    // Pass the structure to the function by value
    printPoint(p1);

    return 0;
}
