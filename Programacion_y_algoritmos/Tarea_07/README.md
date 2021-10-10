# Tarea 07 - Encriptado y desencriptado de archivos wav

## Organizacion de las carpetas y archivos

```bash
├── Data
│  ├── Decrypt
│  │  ├── ftea_10k.wav
│  │  ├── mtea_10k.wav
│  │  └── seno400.wav
│  ├── Encrypt
│  │  ├── ftea_10k.wav
│  │  ├── mtea_10k.wav
│  │  └── seno400.wav
│  └── Original
│     ├── ftea_10k.wav
│     ├── mtea_10k.wav
│     └── seno400.wav
├── Decrypt
│  ├── main.c
│  ├── Makefile
│  └── tags
├── Encrypt
│  ├── main.c
│  ├── Makefile
│  └── tags
└── Functions
   ├── chaotic_map.c
   ├── chaotic_map.h
   ├── wave.c
   └── wave.h
```

## Compilacion

Los programas principales se encuentran en las carpetas `Decrypt` y `Encrypt`. Cada carpeta contiene su archivo `Makefile`, por lo que el comando para realizar su compilación es el siguiente:

```bash
make
```

## Ejecucción

Para ejecutar el programa se debe seguir la siguiente esquema:

```bash
./main.out $nombre_del_archivo
```

Si por ejemplo se quiere encontrar el archivo `ftea1_10k.wav`, se debe ejecutar el siguiente comando:

```bash
./main.out ftea_10k.wav
```

Este archivo deberá estar ubicado enla carpeta `Data/Original/`.

## Archivos de salida

### Encrypt

Los archivos resultantes del programa que encripta estaran ubicados en `Data/Original/Encrypt/`.

### Decrypt

Los archivos resultantes del programa que encripta estaran ubicados en `Data/Original/Decrypt/`.
