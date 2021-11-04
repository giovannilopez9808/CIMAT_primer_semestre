# Tarea 12 - Métodos númericos

## Organización de archivos

```bash
├── Problema_01
│  ├── Data
│  │  ├── Eigen_3.txt
│  │  ├── Eigen_25.txt
│  │  └── test.txt
│  ├── main.c
│  ├── Makefile
│  ├── Modules
│  │  ├── eigen.c
│  │  ├── eigen.h
│  │  ├── qr.c
│  │  ├── qr.h
│  │  ├── solver.c
│  │  ├── solver.h
│  │  ├── tools.c
│  │  └── tools.h
│  ├── Output
│  │  ├── lambda_Eigen_3.txt
│  │  ├── lambda_Eigen_25.txt
│  │  ├── lambda_test.txt
│  │  ├── vector_Eigen_3.txt
│  │  ├── vector_Eigen_25.txt
│  │  └── vector_test.txt
│  └── tags
├── Problema_02
│  ├── problema02a.py
│  └── problema02b.py
├── Problema_03
│  └── graphic.py
├── Problema_04
│  ├── 4a
│  │  ├── graphic.py
│  │  ├── main.c
│  │  ├── Makefile
│  │  ├── Output
│  │  │  ├── output_17.txt
│  │  │  └── output_34.txt
│  │  └── tags
│  ├── 4b
│  │  ├── graphic.py
│  │  ├── graphic_zoom.py
│  │  ├── main.c
│  │  ├── Makefile
│  │  ├── Output
│  │  │  ├── output_10.txt
│  │  │  ├── output_25.txt
│  │  │  ├── output_50.txt
│  │  │  └── output_100.txt
│  │  └── tags
│  └── Modules
│     ├── spline_cubic.c
│     ├── spline_cubic.h
│     ├── tools.c
│     └── tools.h
└── README.md
```

## Compilación

Cada problema contiene un archivo ``Makefile``. Los programas con terminación ``.py`` realizan las gráficas mostradas en el documento.

## Ejecucción

#### Problema 1

La ejecucción del programa del problema 1 se realiza con el siguiente comando

```
.main.out $nombre_del_archivo
```

donde el `$nombre_del_archivo` puede ser `Eigen_3.txt` o `Eigen_25.txt`. Este generara dos archivos en la carpeta `Output` los cuales contienen los eigenvalores y eigenvectores.


#### Problema 4

La ejecucción del programa del problema 4 se realiza con el siguiente comando

```
.main.out
```

Este generara un archivo en la carpeta `Output`.


