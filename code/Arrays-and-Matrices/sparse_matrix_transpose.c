/*Write a C program to find the transpose of a sparse matrix using 3-tuple representation.*/
#include <stdio.h>

#define MAX 100

// Structure to represent a 3-tuple format
struct Tuple {
    int row;
    int col;
    int value;
};

// Function to convert a matrix to 3-tuple format
int convertToTuple(int matrix[MAX][MAX], int rows, int cols, struct Tuple tuple[]) {
    int k = 1;  // Start from index 1 for non-zero elements
    tuple[0].row = rows;
    tuple[0].col = cols;
    tuple[0].value = 0;  // This will store the total number of non-zero elements

    // Traverse the matrix and store non-zero elements in tuple format
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[k].row = i;
                tuple[k].col = j;
                tuple[k].value = matrix[i][j];
                k++;
                tuple[0].value++;  // Increment the count of non-zero elements
            }
        }
    }
    return k;  // Return the total number of non-zero elements + 1 (for the header)
}

// Function to transpose the sparse matrix in 3-tuple format
void transposeTuple(struct Tuple tuple[], struct Tuple transpose[]) {
    int n = tuple[0].value;  // Number of non-zero elements

    // Transpose the header (rows and cols are swapped)
    transpose[0].row = tuple[0].col;
    transpose[0].col = tuple[0].row;
    transpose[0].value = n;

    // Transpose the rest of the elements
    int k = 1;
    for (int i = 0; i < tuple[0].col; i++) {  // Iterate over columns of the original matrix
        for (int j = 1; j <= n; j++) {  // Iterate over all non-zero elements
            if (tuple[j].col == i) {
                transpose[k].row = tuple[j].col;
                transpose[k].col = tuple[j].row;
                transpose[k].value = tuple[j].value;
                k++;
            }
        }
    }
}

// Function to print a matrix in 3-tuple format
void printTuple(struct Tuple tuple[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", tuple[i].row, tuple[i].col, tuple[i].value);
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    struct Tuple tuple[MAX], transpose[MAX];

    // Input the size of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Convert the matrix to 3-tuple format
    int size = convertToTuple(matrix, rows, cols, tuple);

    // Print the original matrix in 3-tuple format
    printf("Original matrix in 3-tuple format:\n");
    printTuple(tuple, size);

    // Transpose the matrix in 3-tuple format
    transposeTuple(tuple, transpose);

    // Print the transposed matrix in 3-tuple format
    printf("Transposed matrix in 3-tuple format:\n");
    printTuple(transpose, size);

    return 0;
}
