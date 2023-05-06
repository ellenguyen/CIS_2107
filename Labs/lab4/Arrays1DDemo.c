// Elle Nguyen, CIS 2107, Section 4
// Lab 4: 1D Arrays
// To design and implement functions to process 1D Arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// define constants
#define RAND_MIN 0
#define RAND_MAX 100
#define SIZE 40

// function protoptyes
void printArray(int array[], int size);
void fillArray(int array[], int size);
void findWithRange(int array[], int lowSelectedRange, int highSelectedRange);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange);
int findSequence(int array[], int num1, int num2);

// function main begins program execution
int main(int arguc, char** argv) {
    // array declaration
    int array[SIZE];

    // testing fillArray function
    fillArray(array, SIZE);

    // display array
    puts("Original array: ");
    printArray(array, SIZE);
    puts("====================================================");

    // testing findWithRange function
    findWithRange(array, 10, 12);
    puts("====================================================");

    // testing reverseArray function
    puts("\nReversed array: ");
    reverseArray(array, SIZE);
    puts("====================================================");

    // testing reverseSelectedRangeWithinArray function
    reverseSelectedRangeWithinArray(array, 10, 20);
    puts("====================================================");

    // declare variable
    int num1, num2;

    // testing findSequence function
    // prompt user for 2 numbers
    printf("%s", "\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // return the matching index
    int index = findSequence(array, num1, num2);

    // output result if found
    printf("sequence found at index %d\n", index);
    puts("====================================================");

    return 0;
}

// fill 1D array with random ints from RAND_MIN to RAND_MAX inclusive
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < SIZE; ++i) {
        array[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
    }
}

// locate largest element between LOW and HIGH
void findWithRange(int array[], int lowSelectedRange, int highSelectedRange) {
    // check if range goes out of bounds
    if (highSelectedRange < lowSelectedRange || lowSelectedRange < RAND_MIN || highSelectedRange < RAND_MIN) {
        // output error message
        printf("%s", "Invalid range indices. Please try again.\n");
        // exit the program for invalid ranges
        exit(1);
    }

    // check if LOW and HIGH equals
    else  if (lowSelectedRange == highSelectedRange) {
        // return the element that matches the range
        for (size_t i = 0; i < SIZE; ++i) {
            if (array[i] == lowSelectedRange) {
                printf("\nThe largest element within the range %d and %d is %d\n", lowSelectedRange, highSelectedRange, array[i]);
                break;
            }
        }
        // output error message
        printf("\nNo such element in the range between %d and %d. Please try again.\n", lowSelectedRange, highSelectedRange);
        // exit the program
        exit(1);
    }

    // function runs if valid
    // initialize max
    int max = -1;
    for (size_t i = 1; i < SIZE; ++i) {
        // skip to next iteration if outside the range
        if (array[i] < lowSelectedRange || array[i] > highSelectedRange) {
            continue;
        }
        // if the current element is larger than current max and within the range, it's the new max
        if (array[i] > max) {
            max = array[i];
        }
    }

    // if max equals -1, there is no largest element
    if (max == -1) {
        printf("\nThere is no largest element within the range %d and %d.\n", lowSelectedRange, highSelectedRange);
    }
    // output largest element within the range
    else {
        printf("\nThe largest element within the range %d and %d is %d\n", lowSelectedRange, highSelectedRange, max);
    }
}

// output result
void printArray(int array[], int size) {
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%5d", array[i]);
        // create a new line after every 10 numbers
        if ((i + 1) % 10 == 0) {
            puts("");
        }
    }
}

// reverse the order of array elements
void reverseArray(int array[], int size) {
    // declare a new array
    int reversed[SIZE];

    for (size_t i = 0; i < SIZE; ++i) {
        // the last element in array will be the first element in the new array and so on
        reversed[i] = array[SIZE - 1 - i];
    }

    // display reversed array
    printArray(reversed, SIZE);
}

// reverse the order of array elements between 2 indices startRange and endRange
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange) {
    printf("\nReversing between %d and %d:\n", startRange, endRange);

    // check if range goes out of bounds
    if (endRange < startRange || startRange < RAND_MIN || endRange < RAND_MIN || endRange >= SIZE) {
        // output error message
        printf("%s", "Invalid range indices. Please try again.\n");
        // exit the program for invalid ranges
        exit(1);
    }

    // check if startRange and endRange equals
    else if (startRange == endRange) {
        // the new array is the original array
        printArray(array, SIZE);
    }

    // fucntion runs if valid
    // declare a new array
    int reversedRange[SIZE];

    // copy the original array to the new array
    for (size_t i = 0; i < SIZE; ++i) {
        reversedRange[i] = array[i];
    }

    // reverse within the specified range
    for (size_t i = startRange; i <= endRange; ++i) {
        reversedRange[i] = array[endRange - i + startRange];
    }

    // display reversed array
    printArray(reversedRange, SIZE);
}

// return index of the first element in the sequence, -1 otherwise
int findSequence(int array[], int num1, int num2) {
    // check for valid input
    if (num1 < RAND_MIN || num2 < RAND_MIN || num1 > RAND_MAX || num2 > RAND_MAX) {
        // output error message
        puts("sequence not found");
        puts("This is not a valid input. Please try again.");

        // exit the program
        exit(1);
    }

    // check for decimals input
    else if (trunc(num1) != num1 || trunc(num2) != num2) {
        // output error message
        puts("sequence not found");
        puts("This is not a valid input. Please try again.");
        
        // exit the program
        exit(1);
    }

    // function runs if valid
    for (size_t i = 0; i < SIZE - 1; ++i) {
        if (array[i] == num1 && array[i + 1] == num2) {
            return i;
        }
    }

    // return -1 if not found
    puts("sequence not found");
    exit(1);
    return -1;
}