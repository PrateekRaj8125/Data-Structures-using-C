/*Write a C program to pass a structure to a function by reference.*/
#include <stdio.h>

// Define a structure
struct Point {
    int x;
    int y;
};

// Function to modify the structure's members, passed by reference
void movePoint(struct Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    struct Point p1 = {10, 20};

    printf("Before moving: x = %d, y = %d\n", p1.x, p1.y);

    // Pass the address of the structure to the function
    movePoint(&p1, 5, -3);

    printf("After moving: x = %d, y = %d\n", p1.x, p1.y);

    return 0;
}
