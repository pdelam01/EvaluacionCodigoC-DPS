/**
 * Exercise 2: profiling - perf
 * 
 * 1. What does the following code segment do?
 * 
 * 
 * 2. Comment the rules and recommendations that are being broken.
 * 
 * 
 * 3. Install perf and run it on the code to do profiling. What is the instruction that requieres more CPU time?
 *    Screenshot and explination in the README.
*/

#include <stdio.h>

unsigned long long int factorial(unsigned int i){
    if (i <= 1){
        return 1;
    }
    return i * factorial(i-1);
}

int main(int argc, char *argv[]){
    int i=2, j=3, f=0;

    if (argc==1){
        printf("Factorial of %d is %lld\n", i, factorial(i));
    }else{
        j=atoi(argv[1]);
        for(f=0;f<j;f++){
            printf("Factorial of %d is %lld\n", f, factorial(f));
        }
    }

    return 0;
}