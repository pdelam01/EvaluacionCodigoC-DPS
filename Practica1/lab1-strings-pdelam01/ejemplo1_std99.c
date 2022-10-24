/*
*  Commands used for compiling the code: 
*     gcc ejemplo1.c -o ej1_std99 -Wall -pedantic -std=c99
*     g++ ejemplo1.c -o ej1_std99 -Wall -pedantic -std=c++98
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
/* R or L is not used in C, it is used in C++
*  
*  L --> means wchar_t (wide character)
*  "A" = 41
*  L"B" = 00 42
*
*  R --> means raw string
*  R"(Hello 
*  World)" = Hello \n World
*
*/

/* Compiling with gcc it fails. With g++ it works
const char* s1 = R"foo(  
Hello
World
)foo"; */

const char* s1 = "foo(\nHello\nWorld\n)foo";   /* Null-terminated string literal char * */
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1; /* 
                  *  Return in a void function
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
                                  *  g++ --> error
                                  *  gcc --> not detected
                                  */
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];  /* 
                      *  Only need response[2] for y/n and /0 
                      *
                      *  Undefined behavior if we enter +8 characters
                      */

	printf("Continue? [y] n: ");  
	gets(response);   /* 
                     *  gets is deprecated, it does not check the size of the buffer
                     * 
                     *  Solution: fgets(response, sizeof(response), stdin); 
                     * 
                     *  g++ --> ‘char* gets(char*)’ is deprecated
                     *  gcc --> ‘gets’ is deprecated 
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
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}