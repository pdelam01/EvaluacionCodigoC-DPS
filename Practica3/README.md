# MUIC - DPS - Laboratorio 3 - Ejercicios Evaluación Código C (DCL SEI CERT)

## Reglas y Recomendaciones  DCL SEI CERT
### Reglas
```
• DCL30-C. Declare objects with appropriate storage durations
• DCL31-C. Declare identifiers before using them
• DCL36-C. Do not declare an identifier with conflicting linkage classifications
• DCL37-C. Do not declare or define a reserved identifier
• DCL38-C. Use the correct syntax when declaring a flexible array member
• DCL39-C. Avoid information leakage when passing a structure across a trust boundary
• DCL40-C. Do not create incompatible declarations of the same function or object
• DCL41-C. Do not declare variables inside a switch statement before the first case label
```
### Recomendaciones
```
• DCL00-C. Const-qualify immutable objects
• DCL01-C. Do not reuse variable names in subscopes
• DCL02-C. Use visually distinct identifiers
• DCL03-C. Use a static assertion to test the value of a constant expression
• DCL04-C. Do not declare more than one variable per declaration
• DCL05-C. Use typedefs of non-pointer types only
• DCL06-C. Use meaningful symbolic constants to represent literal values
• DCL07-C. Include the appropriate type information in function declarators
• DCL08-C. Properly encode relationships in constant definitions
• DCL09-C. Declare functions that return errno with a return type of errno t
• DCL10-C. Maintain the contract between the writer and caller of variadic functions
• DCL11-C. Understand the type issues associated with variadic functions
• DCL12-C. Implement abstract data types using opaque types
• DCL13-C. Declare function parameters that are pointers to values not changed by the function as const
• DCL15-C. Declare file-scope objects or functions that do not need external linkage as static
• DCL16-C. Use ”L,”not ”l,”to indicate a long value
• DCL17-C. Beware of miscompiled volatile-qualified variables
• DCL18-C. Do not begin integer constants with 0 when specifying a decimal value
• DCL19-C. Minimize the scope of variables and functions
• DCL20-C. Explicitly specify void when a function accepts no arguments
• DCL21-C. Understand the storage of compound literals
• DCL22-C. Use volatile for data that cannot be cached
• DCL23-C. Guarantee that mutually visible identifiers are unique
 ```

 ### Programas y código:
 ### Parte de Reglas:
 - **ejercicioInt.c**: pequeño programa con 2 reglas SEI CERT descritas.
 - **bloque1_DCL.c**: ejercicio 1. Definición de reglas DCL que han sido vulneradas/rotas. 
- **bloque1_2_DCL.c**: ejercicio 2. Explicación del código, problemas vistos y definición de reglas DCL que han sido vulneradas.
- **bloque1_3_DCL.c**: ejercicio 3. Los archivos asociados a este:
    - **bloque1_3_main_DCL.c**: archivo principal.
    - **solution1_3_compilers.md**: archivo con la salida obtenida al ejecutar los programas de analisis estático de código C.

### Parte de Recomendaciones:
- **bloque2_RDCL.c**: ejercicio 1. Explicación del código y definición de recomendaciones DCL que han sido vulneradas. Solución propuesta.
- **bloque2_2_RDCL.c**: ejercicio 2. Función factorial. Explicación del código y definición de recomendaciones y reglas que han sido vulneradas. Prueba de la herramienta *perf* para *profiling*.
- **bloque2_3_RDCL.c**: ejercicio 3. Herramienta *perf* para *profiling*. Función fibonacci. 
