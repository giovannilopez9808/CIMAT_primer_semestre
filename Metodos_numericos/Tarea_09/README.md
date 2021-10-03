# Tarea 09 - Giovanni Gamaliel López Padilla

## Organizacion de carpetas

```bash
├── Data
│  ├── Eigen_3x3.txt
│  ├── Eigen_50x50.txt
│  ├── Eigen_125x125.txt
├── Deflection_method
│  ├── main.c
│  ├── Makefile
│  └── Output
│     ├── Eigen_3x3.txt
│     ├── Eigen_50x50.txt
│     ├── Eigen_125x125.txt
├── Functions
│  ├── solvers.h
│  └── tools.h
├── Inverse_method
│  ├── main.c
│  ├── Makefile
│  └── Output
│     ├── Eigen_3x3.txt
│     ├── Eigen_50x50.txt
│     └── Eigen_125x125.txt
└── Power_method
   ├── main.c
   ├── Makefile
   └── Output
      ├── Eigen_3x3.txt
      ├── Eigen_50x50.txt
      └── Eigen_125x125.txt
```

## Compilación

El comando utilizado para compilar cada archivo es el siguiente

```bash
gcc -Wall -Wextra -Werror -pedantic -ansi -o main.out main.c -std=c11 -lm
```

## Ejecución

Para la ejecucción de los programas se realiza con el siguiente comando:

```bash
./main.out $nombre_del_archivo
```

donde `nombre_del_archivo` debe ser el nombre de algún archivo contenido en la carpeta `Data`. Por ejemplo, si se quiere realizar la ejecución con el archivo `Eigen_3x3.txt`, el comando deberia ser el siguiente:

```bash
./main.out Eigen_3x3.txt
```

## Resultados

Los resultados de los programas son guardados en la carpeta `Output` con el mismo nombre que el archivo que contenia a la matriz. La carpeta `Output` se encuentra de forma independiente para cada método realizado.
