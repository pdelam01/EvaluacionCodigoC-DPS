# Factorial & Fibonacci - Exercice 2: perf - profiling

## Primera parte del código: profiling de la función factorial:
Comandos ejectuados:
```
make bloque2_2_RDCL                # Compilación del código
sudo perf stat ./bloque2_2_RDCL.o  # Estadisticas de ejecución
```
Resultados obtenidos:
![Perf results factorial()](imgs/perf_fac.png "Perf results factorial()")

En la imagen superior se pueden observar las estadicticas de ejecución del programa factorial, tratando de hallar el valor para 12 (por defecto el número a calcular si no se le pasa ningún argumento). 

Pasamos ahora a correrlo con una valor elevado y vemos las estadisticas en tiempo de ejecución:
```
./bloque2_2_RDCL.o 1000000        # Determinamos el factorial de 1000000
sudo perf top                     # Vemos las estadisticas de ejecución
```
![Perf top results factorial()](imgs/perf_top_fac.png "Perf top results factorial()")

Para desamblar el código ejecutado y ver las instrucciones que más CPU emplean, *enter* en nuestro programa y *enter* en *Anotate Module*. Observamos lo siguiente:
![Perf top results factorial()](imgs/perf_top_desam_fac.png "Perf top results factorial()")
La instrucción que más CPU consume es *mov*, con un 28,83% del total. Mov se encarga de mover datos entre registros y memoria. Al ser recursiva, la función factorial() llama a si misma, por lo que se ejecuta varias veces, y por lo tanto, mov, donde el acceso a memoria es la instrucción que más CPU consume.

## Segunda parte del código: profiling de la función de fibonacci:
Comandos ejectuados:
```
make bloque2_3_RDCL                # Compilación del código
sudo perf stat ./bloque2_3_RDCL.o  # Estadisticas de ejecución
```
Resultados obtenidos:
![Perf results fibonacci()](imgs/perf_fib.png "Perf results fibonacci()")