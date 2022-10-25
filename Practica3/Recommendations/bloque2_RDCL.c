/**
 * Declarations and Initialization (DCL) - SEI CERT C Coding Standard - Recommendations
 * 
 * Recommendations:
 *  • DCL00-C. Const-qualify immutable objects
 *  • DCL01-C. Do not reuse variable names in subscopes
 *  • DCL02-C. Use visually distinct identifiers
 *  • DCL03-C. Use a static assertion to test the value of a constant expression
 *  • DCL04-C. Do not declare more than one variable per declaration
 *  • DCL05-C. Use typedefs of non-pointer types only
 *  • DCL06-C. Use meaningful symbolic constants to represent literal values
 *  • DCL07-C. Include the appropriate type information in function declarators
 *  • DCL08-C. Properly encode relationships in constant definitions
 *  • DCL09-C. Declare functions that return errno with a return type of errno t
 *  • DCL10-C. Maintain the contract between the writer and caller of variadic functions
 *  • DCL11-C. Understand the type issues associated with variadic functions
 *  • DCL12-C. Implement abstract data types using opaque types
 *  • DCL13-C. Declare function parameters that are pointers to values not changed by the function as const
 *  • DCL15-C. Declare file-scope objects or functions that do not need external linkage as static
 *  • DCL16-C. Use ”L,”not ”l,”to indicate a long value
 *  • DCL17-C. Beware of miscompiled volatile-qualified variables
 *  • DCL18-C. Do not begin integer constants with 0 when specifying a decimal value
 *  • DCL19-C. Minimize the scope of variables and functions
 *  • DCL20-C. Explicitly specify void when a function accepts no arguments
 *  • DCL21-C. Understand the storage of compound literals
 *  • DCL22-C. Use volatile for data that cannot be cached
 *  • DCL23-C. Guarantee that mutually visible identifiers are unique
 * 
 * Variadic functions: functions that accept a variable number of arguments. The number of arguments is not specified in the function declaration.
*/

/**
 * 1. What does the following code segment do?
 *    This example shows a variadic function call average() that calculates the average value of the positive numbers passed like arguments to the function.
 *    Until it encounters the variable va_eol (-1), the function processes the all arguments passed to it, calculating the average value.
 * 
 * 2. What is the variable va_eol used for?
 *    It is used as a flag to indicate the end of the list of arguments passed to the function.
 * 
 * 3. Copy the code segment in a .c program so that we get no warning when we compile in gcc. 
 *    error: unknown type name ‘va_list’
 *    note: ‘va_list’ is defined in header ‘<stdarg.h>’; did you forget to ‘#include <stdarg.h>’?
 *    error: implicit declaration of function ‘va_start’
 *    error: implicit declaration of function ‘va_arg’
 *    error: expected expression before ‘int’
 *    error: implicit declaration of function ‘va_end’
 * 
 *    Adding the header <stdarg.h> solves the problem.
*/

#include <stdarg.h>

enum { va_aeol = -1}; /* --> DCL06-C. Use meaningful symbolic constants to represent literal values <-- */

/* --> DCL10-C. Maintain the contract between the writer and caller of variadic functions <-- */
unsigned int average(int first, ...){
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;

    va_start(args, first);

    while (i != va_aeol){
        sum += i;
        count++;
        i = va_arg(args, int);
    }

    va_end(args);
    return (count ? (sum / count) : 0);
}

// In order to call function average(): average(1, 2, 3, 4, 5, va_aeol);