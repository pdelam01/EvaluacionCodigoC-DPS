/**
 * Heap Overflow exercise
 * 
 * Main goal: execute the f_entrar function exploiting the address and calling the function address from rip after the exploit.
*/


#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

/**
 * Two structs: both stored in memory, in the heap segment:
 * 
 * - s_data: buff[64], an array with enough space for 64 characters
 * - s_fp: fp pointer, a 4Byte pointer, known as RAM address
*/
struct s_data {
    char buffer[64];
};

struct s_fp {
    int (*fp)();
};

/**
 * f_entrar(): prints a message "Pasando"
*/
void f_entrar(){
    printf("Pasando\n");
}

/**
 * f_espero_fuera(): prints a message "Esperando fuera"
*/
void f_espero_fuera(){
    printf("Esperando fuera\n");
}

/**
 * main function: with malloc(), allocates storage in the heap for the structs.
 *                The fp pointer points to the f_espero_fuera() function.
 *                strcpy() copies data from user input to the buffer, without checking the given input.
*/
int main(int argc, char **argv){
    struct s_data * s_midat;
    struct s_fp *f;

    s_midat = malloc (sizeof(struct s_data));
    f = malloc(sizeof(struct s_fp));
    f->fp = f_espero_fuera;

    printf("data: está en [%p], el puntero fp está en [%p]\n", s_midat, f);

    strcpy(s_midat->buffer, argv[1]);

    f->fp();

}

