## 5. Perform a static analysis of the erroneous code and copy the result into your solution.
    Use the tools:
       - rats
       - cppcheck
       - splint
       - vera++
       - valgrind

--> rats <-- 
```bash
COMMAND: rats bloque1_3_erroneo.c
RESULTS: no problems were found

    Entries in perl database: 33
    Entries in ruby database: 46
    Entries in python database: 62
    Entries in c database: 334
    Entries in php database: 55
    Analyzing bloque1_3_DCL.c
    Total lines analyzed: 16
    Total time 0.000695 seconds
    23021 lines per second
```

--> cppcheck <--
```bash
COMMAND: cppcheck --enable=all --library=posix bloque1_3_erroneo.cpp
RESULTS: style: The function 'func' is never used. [unusedFunction]

    Checking bloque1_3_erroneo.cpp ...
    bloque1_3_erroneo.cpp:5:0: style: The function 'func' is never used. [unusedFunction]
```

--> splint <--
```bash
COMMAND: splint bloque1_3_erroneo.c
RESULTS: Fall through case (no preceding break) x2
         Statement after switch is not a case: int i = 4. The first statement after a switch is not a case.
         
    Splint 3.1.2 --- 21 Feb 2021

    bloque1_3_erroneo.c: (in function func)
    bloque1_3_erroneo.c:11:14: Fall through case (no preceding break)
        Execution falls through from the previous case (use /*@fallthrough@*/ to mark
        fallthrough cases). (Use -casebreak to inhibit warning)
    bloque1_3_erroneo.c:13:17: Fall through case (no preceding break)
    bloque1_3_erroneo.c:8:19: Statement after switch is not a case: int i = 4
        The first statement after a switch is not a case. (Use -firstcase to inhibit warning)

    Finished checking --- 3 code warnings
```

--> vera++ <--
```bash
COMMAND: vera++ bloque1_3_erroneo.c
RESULTS:

    bloque1_3_erroneo.cpp:1: no copyright notice found
    bloque1_3_erroneo.cpp:10: trailing whitespace
    bloque1_3_erroneo.cpp:14: comma should be followed by whitespace
    bloque1_3_erroneo.cpp:15: closing curly bracket not in the same line or column
    bloque1_3_erroneo.cpp:16: no newline at end of file
    bloque1_3_erroneo.cpp:16: closing curly bracket not in the same line or column
```

--> valgrind <--
```bash
COMMAND: valgrind --leak-check=full ./bloque1_3_erroneo.o
RESULTS: for func(0):

==22302== Memcheck, a memory error detector
==22302== Copyright (C) 2002-2022, and GNU GPLd, by Julian Seward et al.
==22302== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==22302== Command: ./output.o
==22302== 
17
==22302== 
==22302== HEAP SUMMARY:
==22302==     in use at exit: 0 bytes in 0 blocks
==22302==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==22302== 
==22302== All heap blocks were freed -- no leaks are possible
==22302== 
==22302== For lists of detected and suppressed errors, rerun with: -s
==22302== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

RESULTS: for func(4):
==22643== Memcheck, a memory error detector
==22643== Copyright (C) 2002-2022, and GNU GPLd, by Julian Seward et al.
==22643== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==22643== Command: ./output2.o
==22643== 
==22643== Conditional jump or move depends on uninitialised value(s)
==22643==    at 0x48D6EE0: __vfprintf_internal (vfprintf-internal.c:1516)
==22643==    by 0x48C33DA: printf (printf.c:33)
==22643==    by 0x109169: func (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643==    by 0x109184: main (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643== 
==22643== Use of uninitialised value of size 8
==22643==    at 0x48BD5BB: _itoa_word (_itoa.c:177)
==22643==    by 0x48D6AF3: __vfprintf_internal (vfprintf-internal.c:1516)
==22643==    by 0x48C33DA: printf (printf.c:33)
==22643==    by 0x109169: func (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643==    by 0x109184: main (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643== 
==22643== Conditional jump or move depends on uninitialised value(s)
==22643==    at 0x48BD5CC: _itoa_word (_itoa.c:177)
==22643==    by 0x48D6AF3: __vfprintf_internal (vfprintf-internal.c:1516)
==22643==    by 0x48C33DA: printf (printf.c:33)
==22643==    by 0x109169: func (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643==    by 0x109184: main (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643== 
==22643== Conditional jump or move depends on uninitialised value(s)
==22643==    at 0x48D7533: __vfprintf_internal (vfprintf-internal.c:1516)
==22643==    by 0x48C33DA: printf (printf.c:33)
==22643==    by 0x109169: func (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643==    by 0x109184: main (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643== 
==22643== Conditional jump or move depends on uninitialised value(s)
==22643==    at 0x48D6C4F: __vfprintf_internal (vfprintf-internal.c:1516)
==22643==    by 0x48C33DA: printf (printf.c:33)
==22643==    by 0x109169: func (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643==    by 0x109184: main (in /home/pdelam01/Documentos/Dis_Prog_Sec/Practica3/EvaluacionCodigoC-DPS/Practica3/output2.o)
==22643== 
0
==22643== 
==22643== HEAP SUMMARY:
==22643==     in use at exit: 0 bytes in 0 blocks
==22643==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==22643== 
==22643== All heap blocks were freed -- no leaks are possible
==22643== 
==22643== Use --track-origins=yes to see where uninitialised values come from
==22643== For lists of detected and suppressed errors, rerun with: -s
==22643== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 0 from 0)
```