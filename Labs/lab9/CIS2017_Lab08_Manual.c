/*
 * Name:	Elle Nguyen
 * Section:	04
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s); // done
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4); // done
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4); // done
void compareStr(const char *s1, const char *s2); // done
void comparePartialStr(const char *s1, const char *s2, int n); // done
void randomize(void); // done
int tokenizeTelNum(char *num); // done
void reverse(char *text); // done
int countSubstr (char * line, char * sub); // done
int countChar (char * line, char c); // done
int countWords(char *string); // done
void countAlpha(char *string); // done
void startsWithB(char *string[], int size); // done
void endsWithed(char *string[], int size); // done

int main() {

    //random generator
    srand((unsigned) time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    puts("\n");

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\nNumber of words in string is: %d\n\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    puts("");

    //test for endsWithed
    endsWithed(series, size);

    return 0;
}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    // create a new pointer to modify the characters
    const char *sPtr = s;

    // loop until reaching the last string character
    while (*sPtr != '\0') {
        printf("%c", toupper(*sPtr));   // uppercase
        sPtr++;
    }

    puts("");
    
    sPtr = s;   // reassign the pointer to first character

    while (*sPtr != '\0') {
        printf("%c", tolower(*sPtr));   // lowercase
        sPtr++;
    }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    // function atoi takes 1 string parameter as input & returns converted int
    // expect (const char *str) so no asterisk needed

    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

// 3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    // function atof takes 1 string parameter as input & returns converted float
    // expect (const char *str) so no asterisk needed

    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

// 4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    // function strcmp compares 2 strings & returns an integer value indicating relative order of the strings
    int compare = strcmp(s1, s2);

    if (compare < 0) {
        printf("\n\n%s < %s", s1, s2);
    } else if (compare > 0) {
        printf("\n\n%s > %s", s1, s2);
    } else {
        printf("\n\n%s = %s", s1, s2);
    }
}

// 5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    // function strncmp compares at most the first n bytes of s1 and s2.
    int compare = strncmp(s1, s2, n);

    if (compare < 0) {
        printf("\n\nComparison of first %d chars: %s < %s\n", n, s1, s2);
    } else if (compare > 0) {
        printf("\n\nComparison of first %d chars: %s > %s\n", n, s1, s2);
    } else {
        printf("\n\nComparison of first %d chars: %s = %s\n", n, s1, s2);
    }
}

// 6.(Random Sentences) 
void randomize(void) {
    // arrays of pointers to char
    char *article[] = {"the", "a", "one", "some", "any"};
    char *articles[] = {"The", "A", "One", "Some", "Any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};

    char sentence[50] = "";     // initialize an array of char big enough to randomize

    for (size_t i = 0; i < 20; ++i) {
        // function sprintf stores randomized strings in a sentence
        sprintf(sentence, "%s %s %s %s %s %s.", 
                articles[rand() % 5], noun[rand() % 5], 
                verb[rand() % 5], preposition[rand() % 5], 
                article[rand() % 5], noun[rand() % 5]);
        printf("\n%s", sentence);
    }

    puts("");
}

// 7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    puts("");
    // function strtok breaks string into a series of tokens with delim
    char *token = strtok(num, "()-");

    while (token != NULL) {
        printf("%s", token);
        token = strtok(NULL, "()-"); // continue tokenizing the string from previous call
    }
}

// 8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char *tokens[strlen(text)];     // initialize an array containing length of text
    int count = 0;                  // initialize the number of tokens
    
    // function strtok breaks string into a series of tokens with delim
    char* token = strtok(text, " ");

    while (token != NULL) {
        tokens[count] = token;    // store each token inside the array
        token = strtok(NULL, " ");  // continue tokenizing the string from previous call
        ++count;                    // increment count after each token
    }
    
    // output the tokens in reverse order
    for (int i = count - 1; i >= 0; --i) {
        printf("%s ", tokens[i]);
    }
    
    puts("");
   
}

// 9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;              // initialize a counter
    char *linePtr = line;       // initialize a new pointer to line

    // function strstr returns pointer to 1st occurrence of the matched string in the given string
    // increment count whenever strstr returns a non-null pointer (found occurrence)
    // loop until strstr returns a null pointer (no more occurrence)

    while (linePtr = strstr(linePtr, sub)) {
        ++count;
        ++linePtr;
    }

    return count;
}

// 10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;              // initialize a counter
    char *linePtr = line;       // initialize a new pointer to line

    // function strchr returns a pointer to 1st occurrence of c converted to a string character
    // increment count whenever strchr returns a non-null pointer (found occurrence) 
    // loop until strchr returns a null pointer (no more occurrence)

    while (linePtr = strchr(linePtr, c)) {
        ++count;
        ++linePtr;
    }

    return count;
}


// 11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    int abc[26] = {0};     // initialize 0 for all character occurrence

    for (size_t i = 0; string[i] != '\0'; ++i) {
        // function isalpha checks whether a character is an alphabet
        if (isalpha(string[i])) {
            // increment its occurrence
            ++abc[tolower(string[i]) - 'a'];
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        printf("%c,%c | %d\n", 'A' + i, 'a' + i, abc[i]);
    }
}

// 12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;         // initialize a counter

    // function strtok breaks string into a series of tokens with delim
    char *token = strtok(string, " \n");

    // loop until strtok returns a null pointer (no more token)
    while (token != NULL) {
        ++count;                        // increment count whenever a token is found
        token = strtok(NULL, " \n");    // continue tokenizing the string from previous call
    }

    return count;
}

// 13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    for (int i = 0; i < size; ++i) {
        // check for 1st character, lower and upper case included
        if (string[i][0] == 'b' || string[i][0] == 'B') {
            printf("%s ", string[i]);
        }
    }
    puts("");
}

// 14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    for (int i = 0; i < size; ++i) {
        // check for the last 2 characters, lower and upper case included
        if (tolower(string[i][strlen(string[i]) - 2]) == 'e' &&
            tolower(string[i][strlen(string[i]) - 1]) == 'd') {
            printf("%s ", string[i]);
        }
    }
}