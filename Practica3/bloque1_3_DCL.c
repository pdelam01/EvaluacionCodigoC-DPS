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
*/

/**
 * --> DCL41-C. Do not declare variables inside a switch statement before the first case label <--
 *     If we declare and initialice a variable inside a switch statement, and then we try to use them 
 *     inside any of the case statements, those variables will not be initialized and will contain indeterminate values
 * 
 * 1. What does the following code segment do if we call the function func with a 0?
 *    If we enter a 0, the variable i will contanin the value 17. 
 *    Nevertheless, if our input is not 0, the variable i will contain an indeterminate value.
 * 
 * 2. If there is a problem, could you say the line it is on?
 *    Line 53-54: the variable i and call funtion f is declared and initialized inside the switch statement.
 *      
*  3. Create a file with a main and run the code segment.
*     bloque1_3_main.c
*
*  4. Propose a solution to the example that complies with the CMU standards.
*     Line 49-50: declare and initialize the variable i and call the function f outside the switch statement.
*
*  5. Perform a static analysis of the erroneous code and copy the result into your solution.
*     Use the tools:
*       - rats
*       - cppcheck
*       - splint
*       - vera++
*       - valgrind
*      
*/

#include <stdio.h>

extern void f(int i);

void func(int expr){
    int i = 4;
    f(i);

    switch (expr){
        //int i = 4;
        //f(i);
    
        case 0:
            i = 17;
        default:
            printf("%d\n",i);
    }
}