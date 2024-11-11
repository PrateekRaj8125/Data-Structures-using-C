//4.WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>

#define MAX 100

void createTuple(int sparse[MAX][MAX], int tuple[MAX][3], int row, int col) {
    int k = 1; // Start from the second row of tuple (first row is reserved)
    
    // Count non-zero elements and fill the tuple
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sparse[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = sparse[i][j];
                k++;
            }
        }
    }

    // First row of tuple stores number of rows, columns, and non-zero elements
    tuple[0][0] = row;
    tuple[0][1] = col;
    tuple[0][2] = k - 1;
}

void printTuple(int tuple[MAX][3]) {
    int nonZero = tuple[0][2];
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= nonZero; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int sparse[MAX][MAX], tuple[MAX][3];
    int row, col;

    // Input dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Input elements of the sparse matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    // Create the 3-tuple representation
    createTuple(sparse, tuple, row, col);

    // Print the 3-tuple representation
    printf("The 3-tuple representation is:\n");
    printTuple(tuple);

    return 0;
}
