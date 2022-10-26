/**
 * Exercise 2: profiling - perf
 * 
 * 1. What does the following code segment do?
 *    It is a function that calculates the factorial of 12 recursively.
 *    If you specify the number by command line, it calculates the factorial of all the number to the given one.
 *    So that, entering number 12, it calculates the factorial of 0 to 11.
 * 
 * 2. Comment the rules and recommendations that are being broken.
 *    Those rules & recommendations are specified in the code.
 * 
 * 3. Install perf and run it on the code to do profiling. What is the instruction that requieres more CPU time?
 *    Screenshot and explination in the README.
*/

#include <stdio.h>
#include <stdlib.h>

/* --> INT30-C. Ensure that unsigned integer operations do not wrap <-- */
unsigned long long int factorial(unsigned int i){ 
    if (i <= 1){
        return 1;
    }
    return i * factorial(i-1);
}

int main(int argc, char *argv[]){
    /* f & i are int, factorial() expects unsigned int */

    int i=12, j=3, f=0;
    /* 
     * --> DCL00-C. Const-qualify immutable objects <-- | i is constant, so must be name as: const int i;
     * --> DCL01-C. Do not reuse variable names in subscopes <-- | i is defined in main and also in factorial()
     * --> DCL04-C. Do not declare more than one variable per declaration <-- | i, j, f are declared in the same line
     * --> DCL06-C. Use meaningful symbolic constants to represent literal values <-- | if i in main is constant, we should specified it as what it is, declaring it on a enum
     *         enum { const_value = 12 };
     *         if (argc==1){ factorial(const_value); }
    */

    if (argc==1){
        printf("Factorial of %d is %lld\n", i, factorial(i));
    }else{
        j=atoi(argv[1]); /* Allways check values introduced by users */
        for(f=0;f<j;f++){
            printf("Factorial of %d is %lld\n", f, factorial(f));
        }
    }

    return 0;
}