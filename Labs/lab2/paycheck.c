// Elle Nguyen, 02/05/23, CIS 2107 Section 4
// Lab 02 Paycheck
// Write a C program called paycheck to calculate the paycheck for a Temple employee based on the hourlySalary, weeklyTime 
// (working for maximum 40 hours) and overtime (working for more than 40 hours). 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function main begins program execution
int main(int arguc, char** argv) {
    double employeeNumber;  // employee's number
    float hourlySalary;     // hourly pay
    float weeklyTime;       // number of hours, maximum 40 hours
    int overtime;           // number of overtime hours, more than 40 hours
    float fractPart;        // fractional part of a number
    double intPart;         // integeral part of a number
    float regularPay;       // regular pay
    float overtimePay;      // overtime pay
    float NetPay;           // total paycheck

    // output welcoming messages
    puts("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");

    // prompt user for employeeNumber
    printf("%s", "\tEnter Employee Number: ");
    scanf("%lf", &employeeNumber);

    // check if employeeNumber is negative or a decimal
    // get the fractional and integral part of employeeNumber
    fractPart = modf(employeeNumber, &intPart);

    // exit if the integral part is negative or the fractional part exists
    if (intPart < 0 || fractPart > 0) {
        
        // output warning messages
        puts("\n\tThis is not a valid Employee Number.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");

        // exit the program
        exit(1);
    }

    // prompt user for hourlySalary
    printf("%s", "\tEnter Hourly Salary: ");
    scanf("%f", &hourlySalary);

    // check if hourlySalary is negative and exit
    if (hourlySalary < 0) {
        
        // output warning messages
        puts("\n\tThis is not a valid hourly salary amount.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");

        // exit the program
        exit(1);
    }

    // prompt user for weeklyTime
    printf("%s", "\tEnter Weekly Time: ");
    scanf("%f", &weeklyTime);

    // check if hourlySalary is negative and exit
    if (weeklyTime < 0) {
        
        // output warning messages
        puts("\n\tThis is not a weekly time.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");

        // exit the program
        exit(1);
    }

    // check if there is overtime
    if (weeklyTime > 40) {
        regularPay = hourlySalary * 40;
        // get the overtime hours and overtimePay
        overtimePay = (1.5 * hourlySalary) * (weeklyTime - 40);
    }

    // if there is no overtime
    else {
        regularPay = hourlySalary * weeklyTime;
    }

    // get NetPay
    NetPay = regularPay + overtimePay;

    // output paycheck information
    puts("\t==============================");
    printf("\tEmployee #: %d\n", (int) employeeNumber);
    printf("\tHourly Salary: $%.1f\n", hourlySalary);
    printf("\tWeekly Time: %.1f\n", weeklyTime);
    printf("\tRegular Pay: $%.1f\n", regularPay);
    printf("\tOvertime Pay: $%.1f\n", overtimePay);
    printf("\tNet Pay: $%.1f\n", NetPay);
    puts("\t==============================");

    // output closing messages
    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");

    // successfully exit the program
    exit(0);
}