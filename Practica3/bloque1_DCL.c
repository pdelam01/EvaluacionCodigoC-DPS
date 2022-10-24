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
 * 
 * Storage duration: static, thread, automatic and allocated
 *   • static: The object has static storage duration of the whole program
 *   • automatic: The object has automatic storage duration while a enclosing code is being executed (function, while, switch...)
*/

/**
 * 1. Define the rules that are being broken and propouse a solution 
 * 
 * --> DCL30-C. Declare objects with appropriate storage durations <--
 *     Do not attempt to access an object outside of its lifetime. Attempting to do so is 
 *     undefined behavior and can lead to an exploitable vulnerability. 
 *      
*/

#include <stdio.h>
#include <stddef.h>

const char *p;
const char c_str[] = "Todo va bien";

/**
 * This function returns a pointer to a character array with automatic storage duration
 * 
 * This may cause warnings, and programmers should compile code at the highest warning level
 * and resolve any messages that came from the compiling process.
 * Warn message: "warning: function returns address of local variable"
 * 
 * Solution: the array[] must be created in main function and declare it passing it as an argument to the function1()
*/
char *funcion1(char *array, size_t size) {
    array = "Mi Cadena";
    return array;
}

/**
 * In this function, the variable c_str is assigned to a static storage variable p. This is OK,
 * but we are violationg rule DCL30-C, as c_str is going out of its scope. Two possible solutions:
 * 
 * 1. Same storage durations (the choosen one):
 *      Declared p & c_str with static storage duration
 * 
 * 2. Differing storage durations:
 *      p declared as global and c_str as local (in the function). p must be set to NULL, preventing it to have a
 *      indeterminated value.
 * 
 * Solution: declare p with the same storage duration as c_str[] (both static or automatic; in this case static)
*/
void funcion2(){
    p = c_str;
}

void funcion3(void){
    printf("%c \n", *p);
}

int main(void){
    char array[10];
    p = funcion1(array, sizeof(array)/sizeof(array[0])); // An array legnth must be calculated using this expression
    printf("%c \n", *p); // Format ‘%c’ expects argument of type ‘int’, but argument 2 has type ‘const char *
    
    funcion2();
    funcion3();
    printf("%s \n", p);

    return 0;
}

