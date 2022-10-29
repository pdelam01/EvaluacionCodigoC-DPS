# MUIC - DPS - Laboratorio 4 - Ejercicios Evaluación Código (Concurrency SEI CERT)

## Reglas Concurrency SEI CERT - C
• DCL22-C. Use volatile for data that cannot be cached
• CON43-C. Do not allow data races in multithreaded code
• CON31-C. Do not destroy a mutex while it is locked
• CON33-C. Avoid race conditions when using library functions
• CON35-C. Avoid deadlock by locking in a predefined order
• CON37-C. Do not call signal() in a multithreaded program
• CON39-C.Do not join or detach a thread that was previously joined or detached

## Reglas Concurrency SEI CERT - Java
• THI02-J: Notify all waiting threads rather than a single thread
• THI03-J: Always invoke wait() inside a loop
• THI04-J: Ensure that threads performing blocking operations can be terminated
• THI05-J: Do not use stop() to terminate threads
• LCK00-J: Use private final lock objects to synchronize classes that may interact with untrusted code.
• LCK01-J: Do not synchronize on objects that may be reused
• LCK02-J: Do not synchronize on the class object returned by getClass

## Reglas analizadas:
- Para código C:
```
--> CON31-C. Do not destroy a mutex while it is locked <--
--> CON43-C. Do not allow data races in multithreaded code <--
```

- Para código Java:
```
```