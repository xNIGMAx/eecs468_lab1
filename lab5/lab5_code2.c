#include <stdio.h>
#define SIZE 5

// Function to add two matrices and store the result in 'sum'
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE]){
    // Loop through each element of the matrices
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            sum[i][j] = m1[i][j] + m2[i][j]; // Add corresponding elements
        }
    }
    return 0;
}

// Function to multiply two matrices (element-wise multiplication)
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE]){
    // Loop through each element of the matrices
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            product[i][j] = m1[i][j] * m2[i][j]; // Multiply corresponding elements
        }
    }
    return 0;
}

// Function to transpose a matrix
int transposeMatrix(int m[SIZE][SIZE], int transpose[SIZE][SIZE]){
    // Loop through each element of the matrix
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            transpose[i][j] = m[j][i]; // Swap the rows and columns
        }
    }
    return 0;
}

// Function to print a matrix
int printMatrix(int m[SIZE][SIZE]){
    // Loop through each row of the matrix
    for (int i = 0; i < 5; i++){
        printf("[");
        // Loop through each column of the matrix
        for (int j = 0; j < 5; j++){
            printf(" %d ", m[i][j]); // Print each element
        }
        printf("]");
        printf("\n");
    }
    return 0;
}

int main() {
    int m1[SIZE][SIZE] = {{1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}};
    int m2[SIZE][SIZE] = {{25, 24, 23, 22, 21}
    ,{20, 19, 18, 17, 16}
    ,{15, 14, 13, 12, 11}
    ,{10, 9, 8, 7, 6}
    ,{5, 4, 3, 2, 1}};
    
    // Add the matrices and print the result
    printf("Add Matrices:\n");
    int sum[SIZE][SIZE]; // Array to hold the sum of the matrices
    addMatrices(m1, m2, sum); // Call the addition function
    printMatrix(sum); // Print the resulting matrix
    printf("\n");
    
    // Multiply the matrices and print the result
    printf("Get the Product of Matrices:\n");
    int product[SIZE][SIZE]; // Array to hold the product of the matrices
    multiplyMatrices(m1, m2, product); // Call the multiplication function
    printMatrix(product); // Print the resulting matrix
    printf("\n");
    
    // Transpose the first matrix and print the result
    printf("Transpose Matrix:\n");
    int transpose[SIZE][SIZE]; // Array to hold the transposed matrix
    transposeMatrix(m1, transpose); // Call the transpose function
    printMatrix(transpose); // Print the resulting matrix
    printf("\n");
    
    // Print the first matrix
    printf("Print Matrix:\n");
    printMatrix(m1); // Call the print function for m1
    
    
    
}
