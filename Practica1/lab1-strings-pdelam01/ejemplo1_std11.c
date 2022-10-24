/*
*  Commands used for compiling the code: 
*     gcc ejemplo1.c -o ej1_std11 -Wall -pedantic -std=c11
*     g++ ejemplo1.c -o ej1_std11 -Wall -pedantic -std=c++11
*
*  All in all, the same warnings as the ones found in -std=99
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
/* R or L is not used in C, it is used in C++ */
const char* s1 = R"foo(
Hello
World
)foo";
const char* s2 = "\nHello\nWorld\n"; /* gcc --> Undeclared */

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1; /* 
                  * Return in a void function
                  *
                  *  g++ --> error
                  *  gcc --> warning
                  */
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/'); /* 
                                  *  Invalid conversion from 'const char*' to 'char*'
                                  *  const char* is a mutable pointer to an immutable character
                                  *
                                  *  g++ --> error: invalid conversion from ‘const char*’ to ‘char*’
                                  *  gcc --> not detected
                                  */
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	gets(response);   /* 
                     *  gets is deprecated, use fgets
                     * 
                     *  g++ --> char* gets(char*)’ is deprecated
                     *  gcc --> implicit declaration of function ‘gets’; did you mean ‘fgets’?
                     */

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal"; /* 
                                             * ISO C++ forbids converting a string constant to ‘char*’ 
                                             * 
                                             * Solution: const char *ptr_char = "new string literal";
                                             *           char ptr_char[] = "new string literal";
                                             * 
                                             * g++ --> deprecated conversion from string constant to ‘char*’
                                             * gcc --> not detected
                                             */

    int size_array1 = strlen("аналитик"); /* Unused variable */
    int size_array2 = 100;  /* Unused variable */
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик"; /* Unused variable */

    puts(get_dirname(__FILE__));  /* 
                                   * g++ --> deprecated conversion from string constant to ‘char*’ 
                                   * gcc --> not detected
                                   */
        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    /* 
     * C11 in this standard, this functions were deprecated:
     *  strncpy() --> strcpy_s()
     *  strncat() --> strncat_s
     * 
     * gcc & g++ --> no warnings neither errors
     */
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}