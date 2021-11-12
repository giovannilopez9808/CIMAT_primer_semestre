# Tarea 13 - Métodos numéricos

## Organización de archivos

```bash
├── Problema_01
│  ├── graphic.py
│  ├── main.c
│  ├── Makefile
│  ├── Modules
│  │  ├── simpson_algorithm.c
│  │  ├── simpson_algorithm.h
│  │  ├── tools.c
│  │  └── tools.h
│  └── Output
│     ├── f1.csv
│     └── f2.csv
├── Problema_02
│  ├── graphic.py
│  ├── main.c
│  ├── Makefile
│  ├── Modules
│  │  ├── legendre_polynome.c
│  │  ├── legendre_polynome.h
│  │  ├── newton.c
│  │  ├── newton.h
│  │  ├── tools.c
│  │  └── tools.h
│  └── Output
│     ├── 1.csv
│     ├── 2.csv
│     ├── 3.csv
│     ├── 4.csv
│     ├── 5.csv
│     ├── 6.csv
│     └── 7.csv
└── Problema_03
   ├── graphic.py
   ├── main.c
   ├── Makefile
   ├── Modules
   │  ├── gauss_quadrature.c
   │  ├── gauss_quadrature.h
   │  ├── legendre_polynome.c
   │  ├── legendre_polynome.h
   │  ├── newton.c
   │  ├── newton.h
   │  ├── tools.c
   │  └── tools.h
   └── Output
      ├── f1.csv
      └── f2.csv
```

## Compilación

Cada carpeta contiene su archivo `Makefile`, para realizar su ejecución se usa el siguiente comando:

```bash
make
```

## Ejecucción

### Problema 1 y 3

Para los problemas 1 y 3, la ejecucción de los programas se usa el siguiente comando:

```bash
./main.out
```

### Problema 2

Para el problema 2, la ejecucción del programa se realiza con el siguiente comando:

```bash
./main.out $grado_de_polinomio
```

donde `$grado_de_polinomio` es el grado del polinomio. Por ejemplo, para obtener los resultados para el grado 3. El comando es el siguiente:

```bash
./main.out 3
```

## Archivos de salida

Los archivos de resultados de los programas se encuentran en la carpeta `Output` contenido en cada carpeta.
