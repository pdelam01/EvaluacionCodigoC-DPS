/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */


/* 
 *  In this code I have written the list of the all the rules and recommendations that have been broken. 
 *  Running: 'gcc ejemplo1.c -o ej1 -Wall -pedantic -std=c99 -fsanitize=address' the warnings will desappear
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };

//const char* s1 = R"foo( ... )foo";
const char* s1 = "foo(\
Hello\
World\
)foo";
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];  /* --> STRC31-C: Guarantee that storage for strings has sufficient space for character data and the null terminator <-- */
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        //return 1;
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	//gets(response);   
                   /* --> MSC34-C: Do not use deprecated or obsolescent functions <--
                    *      Solution: fgets(response, sizeof(response), stdin);
                    *
                    * Undefined behavior if we enter +8 characters
                    */
  fgets(response,sizeof(response),stdin);
	if (response[0] == 'n')  /* --> STR35-C: Do not copy data from an unbounded source into a fixed-size buffer <-- */
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
    char *ptr_char  = "new string literal";
    //int size_array1 = strlen("аналитик"); /* Unused */
    //int size_array2 = 100;                /* Unused */
    
   // char analitic1[size_array1]="аналитик";  /* --> STR11-C: Do not specify the bound of a character array initialized with a string literal <--*/
   // char analitic2[size_array2]="аналитик";  /* --> STR11-C: Do not specify the bound of a character array initialized with a string literal <--*/
    //char analitic3[100]="аналитик";          /* --> STR11-C: Do not specify the bound of a character array initialized with a string literal <--*/
                                               /*     Solution: analitic3[]="аналитик"; */

    puts(get_dirname(__FILE__)); 

        
    strcpy(key, argv[1]);  /* --> STR35-C: Do not copy data from an unbounded source into a fixed-size buffer <-- 
                            *     Solution: strncpy(key, argv[1], sizeof(key));
                            */
    strcat(key, " = ");  
    strcat(key, argv[2]);  /* --> STR35-C: Do not copy data from an unbounded source into a fixed-size buffer <-- 
                            *     Solution: strncat(key, argv[2], size_t num );
                            */


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
    ptr_char [0] = 'N';   /* --> STRC30-C: Do not modify string literals <-- */
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}