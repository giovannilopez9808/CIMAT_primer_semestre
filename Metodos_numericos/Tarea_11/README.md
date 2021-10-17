# Tarea 11 - Métodos numéricos

## Organización de carpetas y archivos

```bash
├── Data
│  ├── Eigen_3x3.txt
│  ├── Eigen_50x50.txt
│  ├── Eigen_125x125.txt
│  ├── Eigen_500x500.txt
│  └── matrix.txt
├── Functions
│  ├── solvers.c
│  ├── solvers.h
│  ├── tools.c
│  └── tools.h
├── Rayleigh
│  ├── main.c
│  ├── Makefile
│  └── Output
│     ├── Eigen_3x3.txt
│     ├── Eigen_50x50.txt
│     └── Eigen_125x125.txt
└── Sub_space_method
   ├── main.c
   ├── Makefile
   └── Output
      ├── Eigen_125x125.txt
      └── Eigen_500x500.txt
```

## Compilación

Cada método realizado en las carpetas `Rayleigh` y `Sub_space_method` contiene un documento `Makefile`. El archivo `Makefile` contiene las flags y archivos necesarios para la compilación de los programas.

## Ejecución

### Cociente de Rayleigh

Para la ejecucción de los programas se realiza con el siguiente comando:

```bash
./main.out $nombre_del_archivo
```

donde `nombre_del_archivo` debe ser el nombre de algún archivo contenido en la carpeta `Data`. Por ejemplo, si se quiere realizar la ejecución con el archivo `Eigen_3x3.txt`, el comando deberia ser el siguiente:

```bash
./main.out Eigen_3x3.txt
```

### Método de iteraciones simultaneas

Para la ejecucción de los programas se realiza con el siguiente comando:

```bash
./main.out $nombre_del_archivo $dimension_subespacio
```

donde `nombre_del_archivo` debe ser el nombre de algún archivo contenido en la carpeta `Data` y `dimension_subespacio` es la dimension del subespacio $(m)$ tal que
$
1<m\leq n
$
donde $n$ es la dimension de la matriz. Por ejemplo, si se quiere realizar la ejecución con el archivo `Eigen_125x125.txt` con un subespacio de $m=6$, el comando deberia ser el siguiente:

```bash
./main.out Eigen_125x125.txt 6
```

## Resultados

Los resultados de los programas son guardados en la carpeta `Output` con el mismo nombre que el archivo que contenia a la matriz. La carpeta `Output` se encuentra de forma independiente para cada método realizado.

<style TYPE="text/css">
code.has-jax {font: inherit; font-size: 100%; background: inherit; border: inherit;}
</style>
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
    tex2jax: {
        inlineMath: [['$','$'], ['\\(','\\)']],
        skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'] // removed 'code' entry
    }
});
MathJax.Hub.Queue(function() {
    var all = MathJax.Hub.getAllJax(), i;
    for(i = 0; i < all.length; i += 1) {
        all[i].SourceElement().parentNode.className += ' has-jax';
    }
});
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.4/MathJax.js?config=TeX-AMS_HTML-full"></script>
