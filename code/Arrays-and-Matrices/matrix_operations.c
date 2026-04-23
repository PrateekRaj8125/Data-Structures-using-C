/*3.Write a program to perform the following operations on a given square matrix:
i. Find the no.of nonzero elements
ii. Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>

int main() {
    int n;
    int nonZeroCount = 0;

    // Input the size of the square matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // i. Find the number of non-zero elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    // ii. Display the upper triangular matrix
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    // iii. Display the elements just above and below the main diagonal
    printf("Elements just above and below the main diagonal:\n");

    // Elements above the main diagonal
    printf("Above the main diagonal: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\n");

    // Elements below the main diagonal
    printf("Below the main diagonal: ");
    for (int i = 1; i < n; i++) {
        printf("%d ", matrix[i][i - 1]);
    }
    printf("\n");

    return 0;
}
