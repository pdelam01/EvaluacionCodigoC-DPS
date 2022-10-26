# Factorial & Fibonacci - Ejercicio2: perf - profiling

## Primera parte del código -> profiling de la función factorial:
Comandos ejecutados:
```
make bloque2_2_RDCL                # Compilación del código
sudo perf stat ./bloque2_2_RDCL.o  # Estadísticas de ejecución
```
Resultados obtenidos:

![Perf results factorial()](imgs/perf_fac.png "Perf results factorial()")

En la imagen superior se pueden observar las estadísticas de ejecución del programa factorial, tratando de hallar el valor para 12 (por defecto el número a calcular si no se le pasa ningún argumento). 

Pasamos ahora a correrlo con un valor elevado y vemos las estadísticas en tiempo de ejecución:
```
./bloque2_2_RDCL.o 1000000        # Determinamos el factorial de 1000000
sudo perf top                     # Vemos las estadisticas de ejecución
```
![Perf top results factorial()](imgs/perf_top_fac.png "Perf top results factorial()")

Para desamblar el código ejecutado y ver las instrucciones que más CPU emplean, *enter* en nuestro programa y *enter* en *Anotate Module*. Observamos lo siguiente:

![Perf top results factorial()](imgs/perf_top_desam_fac.png "Perf top results factorial()")

La instrucción que más CPU consume es *mov*, con un 28,83% del total. Mov se encarga de mover datos entre registros y memoria. Al ser recursiva, la función factorial() se llama a sí misma, por lo que se ejecuta varias veces. Por lo tanto, mov, dado que accede constantemente a memoria, es la instrucción que más CPU consume.

## Segunda parte del código -> profiling de la función de fibonacci:
Comandos ejecutados:
```
make bloque2_3_RDCL                # Compilación del código
sudo perf stat ./bloque2_3_RDCL.o  # Estadisticas de ejecución
```
Resultados obtenidos:

![Perf results fibonacci()](imgs/perf_fib.png "Perf results fibonacci()")

En la imagen superior se pueden observar las estadísticas de ejecución del programa fibonacci.

De nuevo, ejecutamos el programa y observamos las estadísticas en tiempo de ejecución:
```
./bloque2_3_RDCL.o                # Determinamos el fibonacci
sudo perf top                     # Vemos las estadisticas de ejecución
```

![Perf top results fibonacci()](imgs/perf_top_fib.png "Perf top results fibonacci()")

Desamblamos el código, encontramos las instrucciones y cuánta CPU consumen:

![Perf top results fibonacci()](imgs/perf_top_desam_fib.png "Perf top results fibonacci()")

En este caso, la instrucción que más CPU consume es *cmpl*, instrucción de comparación. 