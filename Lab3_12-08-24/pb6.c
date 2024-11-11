/*6.WAP to represent the polynomial of single variable using 1-D array and perform
the addition of two polynomial equations*/
#include <stdio.h>

#define MAX 100

// Function to input a polynomial
void inputPolynomial(int poly[], int degree) {
    printf("Enter the coefficients of the polynomial (from degree 0 to %d):\n", degree);
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

// Function to print a polynomial
void printPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

int main() {
    int degree1, degree2, maxDegree;
    int poly1[MAX] = {0}, poly2[MAX] = {0}, result[MAX] = {0};

    // Input the degree of the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    // Input the first polynomial
    inputPolynomial(poly1, degree1);

    // Input the degree of the second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    // Input the second polynomial
    inputPolynomial(poly2, degree2);

    // Add the two polynomials
    addPolynomials(poly1, poly2, result, degree1, degree2);

    // Determine the maximum degree of the result polynomial
    maxDegree = (degree1 > degree2) ? degree1 : degree2;

    // Print the first polynomial
    printf("First Polynomial: ");
    printPolynomial(poly1, degree1);

    // Print the second polynomial
    printf("Second Polynomial: ");
    printPolynomial(poly2, degree2);

    // Print the resultant polynomial
    printf("Resultant Polynomial after addition: ");
    printPolynomial(result, maxDegree);

    return 0;
}
