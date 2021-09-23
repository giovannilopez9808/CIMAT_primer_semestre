# Comandos de compilación

## Ecuación de transferencia de calor

La compilación de los programas contenidos en las carpetas `Problema_1a` y `Problema_1b` se realizaron con el siguiente comando:

```bash
gcc −Wall −Wextra −Werror −pedantic −ansi −o main.out main.c −std=c11 −lm
```

### Problema 1a

Para ejecutar el programa contenido en la carpeta `Problema_1a` se usa el siguiente comando:

```bash
./main.out
```

### Problema 1b

Para ejecutar el programa contenido en la carpeta `Problema_1b` se usa el siguiente comando:

```bash
./main.out
```

## Métodos iterativos

La compilación de los programas contenidos en las carpetas `Problema_2a` y `Problema_2b` se realizaron con el siguiente comando:

```bash
gcc −Wall −Wextra −Werror −pedantic −ansi −o main.out main.c −std=c11 −lm
```

La ejecución de los programas se realiza con el siguiente comando:

```bash
./main.out matrix vector
```

donde `matrix` es el archivo que contiene la información de la matriz y `vector` es el archivo que contiene la información del vector de términos independientes.

Por ejemplo, si el archivo `matrix` es `M_sys_3x3.txt` y el archivo `vector` es `V_sys_3x1.txt`, el comando deberia de ser el siguiente:

```bash
./main.out M_sys_3x3.txt V_sys_3x1.txt
```
