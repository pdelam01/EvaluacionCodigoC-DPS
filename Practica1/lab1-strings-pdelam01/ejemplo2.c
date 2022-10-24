/* Command used for compiling: gcc ejemplo2.c -o ej2 -fsanitize=address -static-libasan -g */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/*
*   No errores found
*/ 
void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

/*
*   ==15905==ERROR: LeakSanitizer: detected memory leaks
*   
*   Leak of 100B, produced because there is no free. We have only reserved memory 
*   for the string, but we have not freed it.
*
*/ 
void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    //Solution: free(s);
}

/*
*   ==16374==ERROR: AddressSanitizer: heap-use-after-free
*   
*   We have freed the memory (line 38) and used it later (line 39). This is a
*   use after free error.
*/ 
void optionThree(){
    char *s = (char *) malloc(100);
    free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    //Solution: free(s); Delete line 41
}

/*
*   ==16426==ERROR: AddressSanitizer: heap-buffer-overflow
*   
*   Warning: writing 19 bytes into a region of size 18 overflows the destination.
*   We are trying to copy 19 bytes into a string of fixed size (18 bytes), not taking into
*   account the null character '\0'. This is a buffer overflow error.
*/ 
void optionFour(){
    char *s = (char *) malloc(18);
    //Solution: char *s = (char *) malloc(19); '\0' character
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}