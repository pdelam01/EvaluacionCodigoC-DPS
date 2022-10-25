# Factorial & Fibonacci - Exercice 2: perf - profiling

## Primera parte del código: profiling de la función factorial:
Comandos ejectuados:
```
gcc -std=c11 bloque2_2_RDCL.c -o bloque2_2_RDCL.o
perf stat ./bloque2_2_RDCL.o
```
Resultados obtenidos:
![Perf results factorial()](imgs/perf_fac.png "Perf results factorial()")


## Segunda parte del código: profiling de la función de fibonacci:
Comandos ejectuados:
```
gcc -std=c11 bloque2_3_RDCL.c -o bloque2_3_RDCL.o
perf stat ./bloque2_3_RDCL.o
```
Resultados obtenidos:
![Perf results fibonacci()](imgs/perf_fib.png "Perf results fibonacci()")