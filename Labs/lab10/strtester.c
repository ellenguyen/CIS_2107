/*
 * Name:	Elle Nguyen
 * Section:	04
 * Lab:  	Lab09. String Library
 * Goal: 	To create my own library of string functions
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int all_letters(char *s); // done
int num_in_range(char *s1, char b, char t); // done
int diff(char *s1, char *s2); // done
void shorten(char *s, int new_len); // done
int len_diff(char *s1, char *s2); // done
void rm_left_space(char *s); // done
void rm_right_space(char *s); // done
void rm_space(char *s); // done
int find(char *h, char *n); // done
char *ptr_to(char *h, char *n); // done
int is_empty(char *s); // done
char *str_zip(char *s1, char *s2); // done
void capitalize(char *s); // done
int strcmp_ign_case(char *s1, char *s2); // done
void take_last(char *s, int n); // done
char *dedup(char *s); // done
char *pad(char *s, int d); // done
int ends_with_ignore_case(char *s, char *suff); // done
char *repeat(char *s, int x, char sep); // done
char *replace(char *s, char *pat, char *rep); // done
char *str_connect(char **strs, int n, char c); // done
void rm_empties(char **words); // done
char **str_chop_all(char *s, char c); // done

int main(int argc, char const *argv[]) {

    // Test for all_letters
    puts("Test for all_letters:");
    char *s1 = "abcdefghijklmnopqrstuvwxyz";
    char *s2 = "abcdefghijklmnopqrstuvwx123";

    if (all_letters(s1)) {
        printf("s1: %s contained all the letters\n", s1);
    } else {
        printf("s1: %s did not contain all the letters\n", s1);
    }

    if (all_letters(s2)) {
        printf("s2: %s contained all the letters\n", s2);
    } else{
        printf("s2: %s did not contain all the letters\n", s2);
    }

    // Test for num_in_range
    puts("\nTest for num_in_range:");
    char start = 'a';
    char end = 'd';
    printf("In s2: %s there are %d letters between %c and %c", s2, num_in_range(s2, start, end), start, end);

    // Test for diff
    puts("\n\nTest for diff:");
    char* s3 = "Hello";
    char* s4 = "Mellow";
    printf("The diff between %s and %s is %d", s3, s4, diff(s3, s4));

    // Test for shorten
    puts("\n\nTest for shorten:");
    char s5[11] = "Watermelon";
    int newSz = 5;
    printf("%s reduced to a length of %d is: ", s5, newSz);
    shorten(s5, newSz);
    printf("\"%s\"", s5);

    // Test for len_diff
    puts("\n\nTest for len_diff:");
    char s6[11] = "Watermelon";
    printf("The length difference between %s and %s is %d", s3, s6, len_diff(s3, s6));

    // Test for rm_left_space
    puts("\n\nTest for rm_left_space:");
    char sp[16] = "   Hello";
    printf("\'%s\' after removing spaces is ", sp);
    rm_left_space(sp);
    printf("\'%s\'", sp);

    // Test for rm_right_space
    puts("\n\nTest for rm_right_space:");
    char sp2[16] = "Hello   ";
    printf("\'%s\' after removing spaces is ", sp2);
    rm_right_space(sp2);
    printf("\'%s\'", sp2);

    // Test for rm_space
    puts("\n\nTest for rm_space:");
    char sp3[16] = "   Hello   ";
    printf("\'%s\' after removing spaces is ", sp3);
    rm_space(sp3);
    printf("\'%s\'", sp3);

    // Test for find
    puts("\n\nTest for find:");
    char* f1 = "chairs";
    char* f2 = "air";
    printf("\'%s\' is found in \'%s\' at index %d", f2, f1, find(f1, f2));

    // Test for ptr_to
    puts("\n\nTest for ptr_to:");
    printf("\'%s\' is found in \'%s\' at pointer %p", f2, f1, ptr_to(f1, f2));

    // Test for is_empty
    puts("\n\nTest for is_empty:");
    char* e1 = "    ";
    char* e2 = "crate";
    printf("e1: \"%s\"\nisEmpty: %d\n\n", e1, is_empty(e1));
    printf("e2: \"%s\"\nisEmpty: %d", e2, is_empty(e2));

    // Test for str_zip
    puts("\n\nTest for str_zip:");
    char* z1 = "Spongebob";
    char* z2 = "Patrick";
    printf("%s zipped with %s is '%s'", z1, z2, str_zip(z1, z2));

    // Test for capitalize
    puts("\n\nTest for capitalize:");
    char sent[12] = "hello world";
    printf("%s capitalized is ", sent);
    capitalize(sent);
    printf("'%s'", sent);

    // Test for strcmp_ign_case
    puts("\n\nTest for strcmp_ign_case:");
    char* c1 = "Hello";
    char* c2 = "hello";
    printf("%s compared with %s is %d", c1, c2, strcmp_ign_case(c1, c2));

    // Test for take_last
    puts("\n\nTest for take_last:");
    char c3[6] = "mango";
    char last = 2;
    printf("The last %d chars of %s are ", last, c3);
    take_last(c3, last);
    printf("%s", c3);

    // Test for dedup
    puts("\n\nTest for dedup:");
    char d1[12] = "Hello";
    printf("removing duplicates from %s: %s", d1, dedup(d1));

    // Test for pad
    puts("\n\nTest for pad:");
    char p1[12] = "Hello";
    int numSpaces = 6;
    printf("Padding '%s' with %d spaces is '%s'", p1, numSpaces, pad(p1, numSpaces));

    // Test for ends_with_ignore_case
    puts("\n\nTest for ends_with_ignore_case:");
    char end1[7] = "Coding";
    char suff[3] = "in";
    int result = ends_with_ignore_case(end1, suff);

    if (result == 1) {
        printf("'%s' ends with '%s'", end1, suff);
    } else {
        printf("'%s' does not end with '%s'",  end1, suff);
    }

    // Test for repeat
    puts("\n\nTest for repeat:");
    char* str = "Hello";
    int num_rep = 3;
    char sep = '-';
    printf("%s repeated %d times sperated by %c is '%s'", str, num_rep, sep, repeat(str, num_rep, sep));

    // Test for replace
    puts("\n\nTest for replace:");
    char* toReplace = "burger king has the best burger";
    char* replacement = "burger";
    char* replacer = "sandwich";
    printf("'%s' where '%s' is replaced with '%s' is \'%s\'", toReplace, replacement, replacer, replace(toReplace, replacement, replacer));

    // Test for str_connect
    puts("\n\nTest for str_connect:");
    int size = 5;
    char* connect[5] = {"I", "Love", "all", "lab", "assignments"};
    char seperator = '_';
    printf("%s", str_connect(connect, size, seperator));

    // Test for rm_empties
    puts("\n\nTest for rm_empties:");
    char* words[7] = {"Hello", "World", " ", " ", "Steph"};
    rm_empties(words);

    // output the array into a string
    int c = 0;
    while (*(words + c) != 0) {
        printf("%s ", *(words + c));
        ++c;
    }

    // Test for str_chop_all
    puts("\n\nTest for str_chop_all:");
    char s23[] = "Hello/World/hello/world";
    char **strs3 = str_chop_all(s23, '/');
    for (size_t i = 0; strs3[i] != NULL; ++i) {
        printf("%s ", strs3[i]);
    }

    return 0;
}

// return 1 if all string characters are either upper- or lower-case letters
// return 0 otherwise
int all_letters(char *s) {
    // loop through each character in s
    while (*s != '\0') {
        // check if out of letters range
        if ((*s < 'A' || *s > 'Z') && (*s < 'a' || *s > 'z')) {
            return 0; // not letters
        }
        ++s; // move to next character
    }
    return 1; // all characters are letters
}

// return number of characters c in s1 such that b<=c<=t
int num_in_range(char *s1, char b, char t) {
    // initialize a counter to return
    int c = 0;

    // loop through each character in s1
    while (*s1 != '\0') {
        // check if current character is within the range
        if (*s1 >= b && *s1 <= t) {
            ++c;
        }
        ++s1;  // move to next character
    }
    // return number of characters within range
    return c;
}

// return number of positions in which s1 and s2 differ
// or return number of changes to transform s1 into s2 (character substitution, insertion, deletion)
int diff(char *s1, char *s2) {
    // initialize a counter for number of different positions
    int count = 0;

    // loop through s1 and s2 at the same time
    while (*s1 != '\0' && *s2 != '\0') {
        // increment count if different
        if (*s1 != *s2) {
            ++count;
        }
        ++s1; // move to next character
        ++s2;
    }

    // loop through the remaining of s1
    while (*s1 != '\0') {
        ++count;
        ++s1;
    }

    // loop through the remaining of s2
    while (*s2 != '\0') {
        ++count;
        ++s2;
    }
    
    return count;
}

// shorten string s to new_len
// if original length of s <= new_len, s is unchanged
void shorten(char *s, int new_len) {
    // initialize a counter for length of s
    int len = 0;

    // calculate length of s
    while (s[len] != '\0') {
        ++len;
    }

    // check if original length of s <= new_len
    if (len <= new_len) {
        return; // s is unchanged
    }

    // put terminated character at position new_len
    s[new_len] = '\0';
}

// return (length of s1 - length of s2)
int len_diff(char *s1, char *s2) {
    // initialize counters for length of both strings
    int len_s1 = 0, len_s2 = 0;

    // calculate length of both strings
    while (s1[len_s1] != '\0') {
        ++len_s1;
    }

    while (s2[len_s2] != '\0') {
        ++len_s2;
    }

    // return the difference in length
    if (len_s1 >= len_s2) {
        return (len_s1 - len_s2);
    } else {
        return (len_s2 - len_s1);
    }
}

// remove whitespace characters from the beginning of s
void rm_left_space(char *s) {
    // initialize a pointer to the start of string s
    char *ptr = s;

    // keep looping until hitting non-null characters
    while (*ptr != '\0' && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')) {
        ++ptr;
    }

    // already loop through all null characters
    // shift string to the left
    while (*ptr != '\0') {
        *s = *ptr;  // copy the character to string s
        ++s;        // move to next character
        ++ptr;
    }

    // put terminated character after truncating whitespace
    *s = '\0';
}

// remove whitespace characters from the end of s
void rm_right_space(char *s) {
    // keep looping until hitting terminated character
    while (*s != '\0') {
        ++s;
    }
    
    // keep looping from the end
    --s;
    while (*s == ' ' || *s == '\t' || *s == '\n') {
        *s = '\0';    // put terminated character once hitting whitespace
        --s;          // move backwards to next character
    }
}

// remove whitespace characters from the beginning and the ending s
void rm_space(char *s) {
    rm_left_space(s);
    rm_right_space(s);
}

// return index of first occurrence of n in string h
// -1 if not found
int find(char *h, char *n) {
    int index = 0;  // initialize a counter to return index of n

    // loop through each character in h
    while (*h != '\0') {
        // return index if found occurrence
        if (*h == *n) {
            return index;
        }

        // keep looping and incrementing otherwise
        ++h;
        ++index;
    }
    return -1;  // not found
}

// return a pointer to first occurrence of n in string h 
// NULL if not found
char *ptr_to(char *h, char *n) {
    // loop through each character in h
    while (*h != '\0') {
        // return current pointer if found occurrence
        if (*h == *n) {
            return n;
        }
        ++h; // keep looping otherwise
    }
    return NULL; // not found
}

// return 1 if s is NULL, consists of only the null character ('') or only whitespace
// 0 if otherwise
int is_empty(char *s) {
    // loop through each character in s
    while (*s != '\0') {
        // return 0 once found non-null character
        if (*s != ' ') {
            return 0;
        }
        ++s; // keep looping
    }
    return 1; // found all null character
}

// return new string consisting of all characters of s1 and s2 interleaved with each other
// if s1 is "Spongebob" and s2 is "Patrick", return string "SPpaotnrgiecbkob"
char *str_zip(char *s1, char *s2) {
    // initialize counters for length of both strings
    int len_s1 = 0, len_s2 = 0, i = 0;

    // calculate length of both strings
    while (s1[len_s1] != '\0') {
        ++len_s1;
    }

    while (s2[len_s2] != '\0') {
        ++len_s2;
    }

    // memory allocation for new string
    int new_len = len_s1 + len_s2;
    char *zip = (char *) malloc(new_len + 1); // typecasting to same type

    if (zip == NULL) {
        return NULL; // cannot allocate memory
    }
    
    // loop through both strings at the same time
    while (*s1 != '\0' && *s2 != '\0') {
        if (i % 2 == 0) {   // copy s1 for even indices
            *zip = *s1;
            ++s1;
        } else {            // copy s2 for odd indices
            *zip = *s2;
            ++s2;
        }
        ++zip;              // move to next character
        ++i;
    }

    // zip any remaining characters in both strings
    while (*s1 != '\0') {
        *zip = *s1;
        ++zip;              // move to next character
        ++s1;
    }

    while (*s2 != '\0') {
        *zip = *s2;
        ++zip;              // move to next character
        ++s2;
    }

    *zip = '\0';            // put the terminated character at the end
    return zip - new_len;   // move pointer back to start of string
}

// change s so first letter of every word in upper case and each additional letter in lower case
void capitalize(char *s) {
    int i = 0;      // initialize a counter for each word
    int cap = 1;    // flag to capitalize next character

    // loop through each word
    while (s[i] != '\0') {
        if (s[i] == ' ') {          // change the flag if hit a space
            cap = 1;
        } else if (cap) {           // convert to uppercase
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            }
            cap = 0;                // change the flag
        } else {                    // convert to lowercase
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        ++i;    // move to next word
    }
}

// compare s1 and s2 ignoring case
// return a positive number if s1 would appear after s2 in the dictionary
// a negative number if it would appear before s2
// 0 if the two are equal
int strcmp_ign_case(char *s1, char *s2) {
    char c1, c2;    // initialize case-insensitive character

    // loop through both strings at the same time
    while (*s1 != '\0' && *s2 != '\0') {
        // convert to lowercase
        c1 = tolower(*s1);
        c2 = tolower(*s2);

        if (c1 > c2) {          // compare in alphabetical order
            return 1;
        } else if (c2 > c1) {
            return -1;
        }
        ++s1;   // move to next character
        ++s2;
    }
    return 0;   // two equal strings
}

// modify s so it consists of only its last n characters
// if n is ≥ the length of s, original string is unmodified
// if call take_last("Brubeck", 5), the original string becomes "ubeck"
void take_last(char *s, int n) {
    // initialize a counter for length of s
    int len = 0;

    // calculate length of s
    while (s[len] != '\0') {
        ++len;
    }

    // s is unchanged
    if (n >= len) {
        return;
    }

    // modify original string
    for (size_t i = 0; i < n; ++i) {
        s[i] = s[len - n + i];
    }

    // put terminated character at the end of new string
    s[n] = '\0';
}

// return new string based on s without duplicate characters
// if s is the string, "There's always money in the banana stand.", return "Ther's alwymonitbd."
// up to the caller to free the memory allocated by the function
char *dedup(char *s) {
    // initialize an array of flags for each ASCII character
    bool seen[256] = {false};

    // initialize a counter for length of s
    int len = 0;

    // loop through each character
    while (s[len] != '\0') {
        ++len;
    }

    // memory allocation for new string
    char *new_str = (char *) malloc(len + 1);
    if (new_str == NULL) {
        return NULL;    // cannot allocate memory
    }

    // initialize a pointer to modify new_str
    char *ptr = new_str;

    // loop through each character
    while (*s != '\0') {
        if (!seen[*s]) {    // if seen first time, change the flag
            seen[*s] = true;
            *ptr = *s;      // copy the non-duplicated character of s
            ++ptr;          // move to next character
        }
        ++s;  // move to next character if already seen
    }

    *ptr = '\0'; // put terminated character
    return new_str;
}

// return new string consisting of all of the letters of s padded with spaces at the end
// total length of returned string is an even multiple of d
// if length of s is already an even multiple of d, return a copy of s
// return NULL if fail or if s is NULL
// return new string otherwise
// up to the caller to free the memory allocated by the function
char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }

    // initialize a counter for length of s
    int len = 0;

    // loop through each character
    while (s[len] != '\0') {
        ++len;
    }

    if (len % d == 0) { // check for multiple of d
        return s;
    }

    // calculate padding of spaces
    int space = d - (len % d);

    // memory allocation for new_str
    char *new_str = (char *) malloc(len + space + 1);
    if (new_str == NULL) {
        return NULL;    // cannot allocate memory
    }

    while (*s != '\0') {
        *new_str = *s;  // copy character to new_str
        ++new_str;      // move to next character
        ++s;
    }

    for (size_t i = 0; i < space; ++i) {
        *new_str = ' '; // add padding
        ++new_str;      // move to next character
    }

    *new_str = '\0';    // put terminated character at the end
    return (new_str - len - space);
}

// return 1 if suff is a suffix of s ignoring case 
// return 0 otherwise
int ends_with_ignore_case(char *s, char *suff) {
       // initialize counters for length of both strings
       int len_s = 0, len_suff = 0;

       // calculate length of both strings
       while (s[len_s] != '\0') {
           ++len_s;
       }

       while (suff[len_suff] != '\0') {
           ++len_suff;
       }

       if (len_s < len_suff) { // cant be suffix
           return 0;
       }

       // compare from the end of both strings
       --len_s;
       --len_suff;
       while (*s != '\0' && *suff != '\0') {
           // convert to lowercase and compare
           if (tolower(*s) != tolower(*suff)) {
               return 0;
           }
           --s;            // move backwards to next character
           --suff;
       }
       return 1;   // suff matches s
}

// return new string consisting of characters in s repeated x times, with the character sep in between
// if s is "all right", x is 3, and sep is ',' return "all right,all right,all right"
// if s is NULL, return NULL
// up to the caller to free the memory allocated by the function
char *repeat(char *s, int x, char sep) {
    if (s == NULL) {
        return NULL;
    }

    // initialize a counter for string length
    int len = 0, new_len = 0;

    // loop through each character
    while (s[len] != '\0') {
        ++len;
    }

    // memory allocation for new_str
    new_len = len * x + x - 1;
    char *new_str = (char *) malloc(new_len);
    if (new_str == NULL) {
        return NULL;    // cannot allocate memory
    }

    for (size_t i = 0; i < x; ++i) {
        while (*s != '\0') {
            *new_str = *s;  // copy s to new_str
            ++new_str;
            ++s;
        }

        s -= len;           // move back to start of string

        if (i < x - 1) {    // use sep (x - 1) times
            *new_str = sep; // put separator
            ++new_str;      // move to next character
        }
    }

    *new_str = '\0';                // put terminated character at the end
    return (new_str - new_len);     // move pointer to start of new_str
}

// return a copy of s with each instance of pat replaced with rep
// len(pat) <, >, or = len(rep)
// allocate memory for the resulting string, up to the caller to free it
// if call replace("NBA X", "X", "rocks"), return "NBA rocks"
char *replace(char *s, char *pat, char *rep) {
    if (s == NULL || pat == NULL || rep == NULL) {
        return NULL;
    }
    
    // initialize counters for length of strings
    int len_s = 0, len_pat = 0, len_rep = 0, len_new_str = 0, i = 0, j = 0;

    // calculate length of each string
    while (s[len_s] != '\0') {
        ++len_s;
    }
    
    while (pat[len_pat] != '\0') {
        ++len_pat;
    }
    
    while (rep[len_rep] != '\0') {
        ++len_rep;
    }

    // memory allocation
    char *new_str = malloc((len_s + 1) * sizeof(char));
    if (new_str == NULL) {
        return NULL;    // cannot allocate memory
    }

    // loop through the string
    while (i < len_s) {
        int occurrence = 1; // flag to detect occurrence of pat
        
        // search for occurrence of pat
        for (j = 0; j < len_pat; ++j) {
            // change the flag if no occurrence
            if (s[i + j] != pat[j]) {
                occurrence = 0;
                break;
            }
        }
    
        // replace pat with rep
        if (occurrence != 0) {
            for (j = 0; j < len_rep; ++j) {
                // copy rep to new_str
                new_str[len_new_str] = rep[j];
                ++len_new_str;  // move to next character
            }
            i += len_pat;
        
        // if no occurrence
        } else {
            // copy original string to new_str
            new_str[len_new_str] = s[i];
            ++len_new_str;      // move to next character
            ++i;
        }
    }

    new_str[len_new_str] = '\0';    // put terminated character
    return new_str;
}

// return a string consisting of first n strings in strs separated by char c
// if strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', return "Washington+Adams+Jefferson"
char *str_connect(char **strs, int n, char c) {
    // initialize counter for length of new_str
    int len = 0;

    // loop through the first n strings
    for (size_t i = 0; i < n; ++i) {
        // pointer to each word
        char *str = strs[i];

        // calculate length of new string
        while (*str != '\0') {
            ++len;
            ++str;  // move to next character
        }

        if (i < n - 1) {    // c connects (n - 1) times
            ++len;  // including length of char
        }
    }
    
    // memory allocation
    char *new_str = malloc(len + n);
    if (new_str == NULL) {
        return NULL;    // cannot allocate memory
    }

    char *ptr = new_str; // pointer to new_str
    
    // loop through the first n strings
    for (size_t i = 0; i < n; ++i) {
        // pointer to each word
        char *str = strs[i];

        while (*str != '\0') {
            *ptr = *str;    // copy to new_str
            ++ptr;          // move to next character
            ++str;
        }

        if (i < n - 1) {    // c connects (n - 1) times
            *ptr = c;       // connector
            ++ptr;          // move to next character
        }
    }

    *ptr = '\0';            // put terminated character
    return new_str;
}

// words is an array of string terminated with a NULL pointer
// remove any empty strings (of length 0) from the array
void rm_empties(char **words) {
    int i = 0;  // pointer to each word in the array
    int j = 0;  // pointer to each character in each word

    // loop through each word
    while (words[i] != NULL) {
        // copy if the current word is not null
        if (!is_empty(words[i])) {
            words[j] = words[i];
            ++j;      // move to next word
        }
        ++i;          // move to next word if null
    }

    words[j] = NULL;  // put terminated character at next element
}

// return a string array of the characters in s split into tokens based on delimeter c, followed by a NULL pointer
// if s is "I am ready for a nice vacation" and c is ' ', return {"I", "am", "ready", "for", "a", "nice", "vacation", NULL}
char **str_chop_all(char *s, char c) {
    int size = 0;
    char **sPtr = NULL;     // initialize pointer to array of char
    char *word = s;         // pointer to each character in s

    // loop through the whole array
    while (*s != '\0') {
        // found delimeter, replace with terminated character
        if (*s == c) {
            *s = '\0';
            // resize the array
            sPtr = realloc(sPtr, (size + 1) * sizeof(char *));

            sPtr[size] = word;      // store the current word
            ++size;                 // increment size for next word
            word = ++s;             // move to next character
        }
        ++s;    // keep looping otherwise
    }

    // resize the array
    sPtr = realloc(sPtr, (size + 1) * sizeof(char *));

    sPtr[size] = word;      // move pointer to last word
    ++size;                 // increment size for terminated character
    sPtr[size] = NULL;      // put terminated character at the end

    return sPtr;            // return pointer to start of array
}