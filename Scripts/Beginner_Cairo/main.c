#include <cairo.h>
#include <stdio.h>
#include <math.h>
/* Compilar desde terminal con gcc cairo_proof.c $(pkg-config --cflags --libs cairo) -lm */
/*
 *Para compilar desde terminal se puede escribir "gcc main.c $(pkg-config --cflags --libs cairo) -lm" o escribir "make"
 * */
/*
En codeblocks agregar a
   setting/compiler/LinkerSettings/OtherLinkerOptions el valor de -lcairo
   setting/compiler/OtherCompilerOptions el valor de `pkg-config --cflags --libs cairo`
*/
#define ScreenX 640
#define ScreenY 480
#define MarginX 40
#define MarginY 20
#define NAME_PNG "grafica.png"

/* Funcion para mostrar puntos en pantalla
 * x: pixel en direccion X
 * y; pixel en direccion Y*/
void put_point(cairo_t *cr,double x, double y,double pointW)
{
    cairo_move_to(cr,x,y);
    cairo_arc(cr,x,y,pointW/2,0,2*M_PI);
}

/* Funcion para unir los puntos  con lineas rectas
 * x: coordenadas del eje X
 * y: coordenadas del eje Y
 * N: numero de puntos*/
void line_fill(cairo_t *cr,double pointW,double *x, double *y, int N)
{
    cairo_set_line_width (cr,pointW/2);
    cairo_set_source_rgb (cr, 0, 0, 1);
    for(int i=0;i<N-1;i++){
	cairo_move_to(cr,x[i],y[i]);
	cairo_line_to(cr,x[i+1],y[i+1]);
	cairo_stroke(cr);
    }
}
void test1(){
	cairo_surface_t *surface;
	cairo_t *cr;
	cairo_font_extents_t fe;
	cairo_text_extents_t te;
	double pointW=10.0;		 //Ancho de punto
	int N=100;
	double x[100],y[100];
	for(int i=0;i<N;i++)
	{
		x[i] = rand()%ScreenX;
		y[i] = rand()%ScreenY;
	}
    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, ScreenX, ScreenY);
    cr = cairo_create (surface);
	/* Drawing code goes here */
	cairo_set_line_width (cr,pointW);
	cairo_set_source_rgb (cr, 255, 255, 255);
	cairo_paint(cr);
	cairo_set_source_rgb (cr, 0, 0, 0);

//Ponemos los puntos de la grafica
	for(int i=0;i<N;i++)
	    put_point(cr,x[i],y[i],pointW);
	cairo_stroke (cr);
  //Unimos los puntos con lineas
	line_fill(cr,pointW,x,y,sizeof(x)/sizeof(double));
	cairo_stroke (cr);

    cairo_surface_write_to_png (surface, NAME_PNG);
    cairo_destroy (cr);
    cairo_surface_destroy (surface);
}
int main (void)
{
	test1();
    return 0;
}
