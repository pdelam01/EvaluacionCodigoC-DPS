/**
 * Exercise using examples of good practices SEI CERT C Coding Standars: Integers 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 *  --> INT31-C. Ensure that integer conversions do not result in lost or misinterpreted data <--
 * 
 *  Converting from a value of an unsigned integer type to a value of a signed integer type may occur in a lost of data
*/
void funcWrong(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  sc = (signed char)u_a;
}

/* We must validate ranges when converting from an unsigned type to a signed type */
void funcRight(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  if (u_a <= SCHAR_MAX) {
    sc = (signed char)u_a;
  }else{
    printf("Error: Value out of range");
  }
}

/**
 *  --> INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors <--
 * 
 *  Division by zero is undefined behavior
*/
void funcDivWrong(signed long s_a, signed long s_b) {
  signed long result;
  if ((s_a == LONG_MIN) && (s_b == -1)) { /* --> INT32-C Ensure that operations on signed integers do not result in overflow */
    /* Handle error */
  } else {
    result = s_a / s_b;
  }
}

/* We must validate that we are not dividing by 0 */
void funcDivRight(signed long s_a, signed long s_b) {
  signed long result;
  if (s_b != 0 || (s_a == LONG_MIN) && (s_b == -1)) { /* --> INT32-C Ensure that operations on signed integers do not result in overflow */
    printf("Error: Can not divide by 0");
  } else {
    result = s_a / s_b;
  }
}