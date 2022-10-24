/**
 * Declarations and Initialization (DCL) - SEI CERT C Coding Standard
 * 
 * Rules:
 *   • DCL30-C. Declare objects with appropriate storage durations
 *   • DCL31-C. Declare identifiers before using them
 *   • DCL36-C. Do not declare an identifier with conflicting linkage classifications
 *   • DCL37-C. Do not declare or define a reserved identifier
 *   • DCL38-C. Use the correct syntax when declaring a flexible array member
 *   • DCL39-C. Avoid information leakage when passing a structure across a trust boundary
 *   • DCL40-C. Do not create incompatible declarations of the same function or object
 *   • DCL41-C. Do not declare variables inside a switch statement before the first case label
*/

/**
 * 1. Define the rules that are being broken and propouse a solution 
 * 
 * --> DCL30-C. Declare objects with appropriate storage durations <--
 *      Do not attempt to access an object outside of its lifetime. Attempting to do so is 
 *      undefined behavior and can lead to an exploitable vulnerability. 
 *      
*/

#include <stdio.h>
#include <stddef.h>

const char *p;

/**
 * This function returns a pointer to a character array with automatic storage duration
 * 
 * This may cause warnings, and programmers should compile code at the highest warning level
 * and resolve any messages that came from the compiling process.
 * Warn message: "warning: function returns address of local variable"
 * 
 * Solution: 
*/
char *funcion1(void){
    char array[10] = "Mi Cadena";
    /* Initialize array */
    return array;
}

/**
 * In this function, the variable c_str is assigned to a static storage variable p. This is OK,
 * but we are violationg rule DCL30-C, as c_str is going out of its scope.
 * 
 * Solution: declare p with the same storage duration
*/
void funcion2(void){
    const char c_str[] = "Todo va bien";
    p = c_str;
}

void funcion3(void){
    printf("%c \n", p);
}

int main(void){
    p = funcion1();
    printf("%c \n", p);
    funcion2();
    funcion3();
    printf("%s \n", p);

    return 0;
}

