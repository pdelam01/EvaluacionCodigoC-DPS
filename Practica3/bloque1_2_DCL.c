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
 * Flexible array struct: at the end of the struct, a flexible array member (size not specified) is declared. At least one other member must be declared.
 * Some restrictions apply:
 *   • The incomplete array type must be the last element within the structure.
 *   • There cannot be an array of structures that contain a flexible array member.
 *   • Structures that contain a flexible array member cannot be used as a member of another structure.
 *   • The structure must contain at least one named member in addition to the flexible array member.
 * 
*/

/**
 * 1. What does the following code segment do?
 *    It declares a structure with a flexible array member. The flexible array member is the last member of the structure. 
 * 
 * 2. If there is a problem, could you say the line it is on?
 *    Line 34: the size of the array declared in the struct is specified (int data [1];) but that should not be done.
 *    Flexible array members on a struct are declared without specifying the size of the array.
 * 
 * 3. Define the rule that is broken and propose a correct alternative following the SEI CERT C.
 *    -->  DCL38-C. Use the correct syntax when declaring a flexible array member <--
*/

#include <stdlib.h>

struct flexArrayStruct {
    int num;
    //int data [1];
    int data[]; // The size of the array is not specified explicitly within the structure
};

void func(size_t array_size){
    /* Space is allocated for the struct */
    struct flexArrayStruct *structP 
        = (struct flexArrayStruct *) 
        malloc(sizeof(struct flexArrayStruct) 
            + sizeof(int) * (array_size - 1));

    if (structP == NULL){
        /* Handle malloc failure */
    }

    structP->num = array_size;

    /**
     * Access data[] as if it had been allocated
     * as data[array_size]
    */
    for (size_t i = 0; i < array_size; i++){
        structP->data[i] = 1;
    }
}
