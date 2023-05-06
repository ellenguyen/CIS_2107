// Elle Nguyen, CIS 2107, Section 4
// Lab 5: Processing 2D Arrays
// To design and implement functions to process 2D Arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Header-file for boolean data-type

// global variable declaration
static int row, column;

// function prototypes
void max(const int array[row][column]);
int rowSum(int row, const int array[][column]);
int columnSum(int col, const int array[][column]);
void isSquare();
void displayOutputs(const int array[row][column]);

// function main begins program execution
int main(void) {
    // output welcoming message
    puts("Let's create a 2Dim array!\n");

    // prompt user for number of rows
    printf("%s", "\tHow many rows? ");
    scanf("%d", &row);

    // prompt user for number of columns
    printf("%s", "\tHow many columns? ");
    scanf("%d", &column);

    puts("");

    // variable declaration
    int array[row][column]; // declare 2D variable-length array

    // prompt user for array entries
    int input;
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d", &input);
            array[i][j] = input;
        }
    }
    // testing max function
    max(array);

    // testing rowSum function
    for (size_t i = 0; i < row; ++i) {
        printf("\nSum of row %u = %d", i + 1, rowSum(i, array));
    }

    puts("");

    // testing columnSum function
    for (size_t j = 0; j < column; ++j) {
        printf("\nSum of column %u = %d", j + 1, columnSum(j, array));
    }

    puts("");

    // testing isSquare function
    isSquare();

    // testing displayOutputs function
    displayOutputs(array);
    return 0;
}

// return max value in 2D array
void max(const int array[row][column]) {
    int max = 0;
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            // if current element is larger than max, max is current element
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    printf("\nThe maximum value is %d.\n", max);
}

// return sum of elements in row x of 2D array
int rowSum(int row, const int array[][column]) {
    int rowSum = 0;
    for (size_t j = 0; j < column; ++j) {
        rowSum += array[row][j];
    }
    return rowSum;
}

// return sum of elements in column x of 2D array
int columnSum(int col, const int array[][column]) {
    int columnSum = 0;
    for (size_t i = 0; i < row; ++i) {
        columnSum += array[i][col];
    }
    return columnSum;
}

// check if the array has same row and column length
void isSquare() {
    // return true if row = column
    if (row == column) {
        puts("\nThis is a square array.\n");
    } else {
        puts("\nThis is not a square array.\n");
    }
}

// display 2D array elements
void displayOutputs(const int array[row][column]) {
    puts("Here is your 2Dim array:");
    for (size_t i = 0; i < row; ++i) {
        printf("[");
        for (size_t j = 0; j < column; ++j) {
            // no comma and space after last element in a row
            if (j == column - 1) {
                printf("%d", array[i][j]);
            } else {
                printf("%d, ", array[i][j]);
            }
        }
        printf("]\n");
    }
}