// Elle Nguyen, 02/05/23, CIS 2107 Section 4
// Lab 02 Revenue
// Write a C program called "revenue" to calculate the revenue 
// from a sale based on the unit price and quantity of a product input by the user

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function main begins program execution
int main(int arguc, char** argv) {
    int itemPrice;          // price of an item
    double quantity;        // item's quantity
    float fractPart;        // fractional part of a number
    double intPart;         // integeral part of a number
    float cost;             // cost before discount
    float discount;         // discount percentage
    float discountAmount;   // discount amount
    float total;            // cost after discount

    // output welcoming messages
    puts("Welcome to \"TEMPLE\" store\n");

    // prompt user for itemPrice
    printf("%s", "\tEnter item price: ");
    scanf("%d", &itemPrice);

    // check if itemPrice is negative and exit
    if (itemPrice < 0) {
        
        // output warning messages
        puts("\n\tThis is not a valid item price.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE\" store");

        // exit the program
        exit(1);
    }

    // prompt user for quantity
    printf("%s", "\tEnter quantity: ");
    scanf("%lf", &quantity);

    // check if quantity is negative or a decimal
    // get the fractional and integral part of quantity
    fractPart = modf(quantity, &intPart);

    // exit if the integral part is negative or the fractional part exists
    if (intPart < 0 || fractPart > 0) {
        
        // output warning messages
        puts("\n\tThis is not a valid quantity order.");
        puts("\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE\" store");

        // exit the program
        exit(1);
    }

    // get discount rate based on quantity
    if (quantity >= 1 && quantity <= 49) {
        discount = 0;
    }
    else if (quantity >= 50 && quantity  <= 99) {
        discount = 10;
    }
    else if (quantity >= 100 && quantity <= 149)  {
        discount = 15;
    }
    else if (discount >= 150) {
        discount = 25;
    }

    // get cost, discountAmount, total
    cost = itemPrice * quantity;
    discountAmount = (float) discount / 100 * cost;
    total = cost - discountAmount;

    // output revenue information
    printf("\tThe item price is: %.1f\n", (float) itemPrice);
    printf("\tThe order is: %d item(s)\n", (int) quantity);
    printf("\tThe cost is: $%.1f\n", cost);
    printf("\tThe discount is: %.1f%%\n", discount);
    printf("\tThe discount amount is: $%.1f\n", discountAmount);
    printf("\tThe total is: $%.1f\n", total);

    // output closing messages
    puts("\nThank you for using \"TEMPLE\" store");
    
    // successfully exit the program
    exit(0);
}