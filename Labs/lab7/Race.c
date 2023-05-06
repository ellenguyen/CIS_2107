// Elle Nguyen - CIS 2107 - Section 4
// Lab 7: Race
// The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
// generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
// controlled using the sleep() function. Sometimes it takes a while due to slippage.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

// function prototyes
int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

// function execution begins
int main() {
    srand((unsigned)time(NULL));

    int hPos = 1;						// hare start position is 1, cannot slip past 1
    int tPos = 1;						// tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	// the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	// the spacing is modeled after the sample

    while (hPos != 70 && tPos != 70) {
        //sleep(1);						// slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos, tPos);
        puts("");
    }

    // decide the winner
    if (tPos >= 70) {
        puts("TORTOISE WINS!!! YAY!!!");
    } else {
        puts("Hare wins. Yuch.");
    }

    return 0;
}

// Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin) {
    if (hMin < tMin) {
        return hMin;
    }
    return tMin;
}

// Prints the position of the H and T
void printRace(int hPos, int tPos) {
    int minPos = min(hPos, tPos);

    for (size_t i = 0; i <= 70; ++i) {
        if (i == hPos && i == tPos) {       // if same position
            printf("OUCH!!!");
        } else if (i == tPos) {
            printf("T");
        } else if (i == hPos) {
            printf("H");
        } else {                            // print space otherwise
            printf(" ");
        }
    }
}

// Controls the tortoise movement
void tortMove(int *tPtr) {
    int tortoise = randomNumberGenerator();

    if (tortoise >= 1 && tortoise <= 5) {         // fast plod (50%) move 3 to the right
        *tPtr += 3;
    } 
    else if (tortoise == 6 || tortoise == 7) {    // slip (20%) move 6 to the left
        *tPtr -= 6;
    }
    else if (tortoise >= 8 && tortoise <= 10) {   // slow pod (30%) move 1 to the right
        *tPtr += 1; 
    }
    
    if (*tPtr < 1) {                              // reset if go past 1
        *tPtr = 1;
    } else if (*tPtr > 70) {
        *tPtr = 70;
    }
}

// Controls the hare movement
void hareMove(int *hPtr) {
    int hare = randomNumberGenerator();

    if (hare == 1 || hare == 2) {         // sleep (20%) no move
        ;
    }
    else if (hare == 3 || hare == 4) {    // big hop (20%) move 9 to the right
        *hPtr += 9;
    }
    else if (hare == 5) {                 // big slip (10%) move 12 to the left
        *hPtr -= 12;
    }
    else if (hare >= 6 && hare <= 8) {    // small hop (30%) move 1 to the right
        *hPtr += 1;
    }
    else if (hare == 9 || hare == 10) {   // small slip (20%) move 2 to the left
        *hPtr -= 2;
    }
    
    if (*hPtr < 1) {                      // reset if go past 1
        *hPtr = 1;
    } else if (*hPtr > 70) {
        *hPtr = 70;
    }
}

// Generates random number from 1-10
int randomNumberGenerator() {
    return rand() % (INT_MAX) + INT_MIN;
}