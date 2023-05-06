// Elle Nguyen, CIS 2107, Section 4
// Lab 6: Arrays of Pointers to Functions
// Design and implement array of function pointer

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printArray(int STUDENTS, int EXAMS, int grades[][EXAMS]);
void minimum(int STUDENTS, int EXAMS, int grades[][EXAMS]);
void maximum(int STUDENTS, int EXAMS, int grades[][EXAMS]);
void average(int STUDENTS, int EXAMS, int grades[][EXAMS]);
void printOption();

int main(void) {
    // define variable
    int option, STUDENTS, EXAMS;
    
    // prompt user for number of rows
    printf("%s", "\tHow many students? ");
    scanf("%d", &STUDENTS);
    
    // prompt user for number of columns
    printf("%s", "\tHow many exams? ");
    scanf("%d", &EXAMS);

    puts("");

    // declare 2D variable-length array
    int grades[STUDENTS][EXAMS];

    // initialize array of 4 pointers to functions that each take 3 arguments and return void
    void (*processGrades[4])(int STUDENTS, int EXAMS, int grades[][EXAMS]) = {printArray, minimum, maximum, average};

    // prompt user for array entries
    int input;
    for (size_t i = 0; i < STUDENTS; ++i) {
        for (size_t j = 0; j < EXAMS; ++j) {
            printf("\tenter [%zu][%zu]: ", i, j);
            scanf("%d", &input);
            grades[i][j] = input;
        }
    }

    // prompt user for option
    printOption();
    scanf("%d", &option);

    // keep running until user hits 4 to exit the program
    while (option != 4) {
        // invoke function at location option in array processGrades and pass option as an argument
        switch (option) {
            case 0:
                (*processGrades[option])(STUDENTS, EXAMS, grades);
                break;

            case 1:
                (*processGrades[option])(STUDENTS, EXAMS, grades);
                break;

            case 2:
                (*processGrades[option])(STUDENTS, EXAMS, grades);
                break;

            case 3:
                (*processGrades[option])(STUDENTS, EXAMS, grades);
                break;

            default:
                break;
        }

        // prompt user for option
        printOption();
        scanf("%d", &option);
    }

    puts("Program execution completed.");
    
    return 0;
}

// output grades in tabular format
void printArray(int STUDENTS, int EXAMS, int grades[][EXAMS]) {
    for (size_t i = 0; i < STUDENTS; ++i) {
        // output label for row
        printf("\nStudent[%zu] ", i);

        // output grades for one student
        for (size_t j = 0; j < EXAMS; ++j) {
            printf("%-5d", grades[i][j]);
        }
    }
    puts("");
}

// find the minimum grade
void minimum(int STUDENTS, int EXAMS, int grades[][EXAMS]) {
    int lowGrade = 100; // initialize to highest possible grade

    // loop through rows of grades
    for (size_t i = 0; i < STUDENTS; ++i) {

        // loop through columns of grades
        for (size_t j = 0; j < EXAMS; ++j) {
            if (grades[i][j] < lowGrade) {
                lowGrade = grades[i][j];
            } 
        } 
    }
    // output the minimum grade
    printf("The lowest grade is: %d\n", lowGrade);
}

// find the maximum grade
void maximum(int STUDENTS, int EXAMS, int grades[][EXAMS]) {
    // initialize to lowest possible grade
    int highGrade = 0;

    // loop through rows of grades
    for (size_t i = 0; i < STUDENTS; ++i) {

        // loop through columns of grades
        for (size_t j = 0; j < EXAMS; ++j) {
            if (grades[i][j] > highGrade) {
                highGrade = grades[i][j];
            } 
        } 
    }
    // output the maximum grade
    printf("The highest grade is: %d\n", highGrade);
}

// determine the average grade of every student
void average(int STUDENTS, int EXAMS, int grades[][EXAMS]) {                                                          
    // total all grades for each student
    for (size_t i = 0; i < STUDENTS; ++i) {
        // sum of test grades
        int total = 0;

        for (size_t j = 0; j < EXAMS; ++j) {
            total += grades[i][j];
        }
        printf("The average grade for student %zu is %.2f\n", i, (double) total / EXAMS);
    }
    puts("");
}

// output options for user
void printOption() {
    // output 4 options
    puts("\nEnter a choice:");
    puts("\t0 Print the array of grades");
    puts("\t1 Find the minimum grade");
    puts("\t2 Find the maximum grade");
    puts("\t3 Print the average on all tests for each student");
    puts("\t4 End Program");
}