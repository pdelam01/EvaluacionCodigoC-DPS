#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

/* 
 * wrapFunctionAdd - returns the sum of the two arguments. 
 *
 * The addition of this two parameters may result in a overflow.
 * In order to avoid that, we will add a precondition test so that we guarantee theres is not a wrap.
 * If UINT_MAX - ui_a < ui_b that means the add of ui_a + ui_b will cause a overflow.
 */
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;

  /* --> INT30-C. Ensure that unsigned integer operations do not wrap <-- */
  if (UINT_MAX - ui_a < ui_b) {
    printf("Error: wrapFunctionAdd() - wrapping detected");
    return -1;
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
}

/*
* wrapFunctionMult - returns the product of the two arguments.
*
* The multiplication of this two parameters may result in a overflow.
* As we did before, we will add a precondition test so that we guarantee theres is not a wrap.
* If UINT_MAX/ui_a < ui_b that means the multiplication of ui_a * ui_b will cause a overflow.
*/
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  
  /* --> INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors <-- */
  if (ui_a == 0 || ui_b == 0) { 
    return 0;
  }

  /* --> INT30-C. Ensure that unsigned integer operations do not wrap <-- */
  if (UINT_MAX / ui_a < ui_b) {
    printf("Error: wrapFunctionMul() - wrapping detected");
    return -1;
  }else{
    umul *= ui_b;
  }
  
  return umul;
}


uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  /* --> INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand <-- */
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 

  /* 
  * Eliminate the possibility of shifting by greater than or equal to the number of bits that exist in the precision of the left and right operand.
  * The builtin_popcount(UINT_MAX) function provide the correct precision for any integer type. 
  */
  if (ui_b >= __builtin_popcount(UINT_MAX)) {
    printf("Error: wrapFunctionMul() - wrapping detected");
    return -1;
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  }

  return uShift;
}
