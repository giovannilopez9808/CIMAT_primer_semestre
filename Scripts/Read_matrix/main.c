#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*************************** FUNCIONES DE LECTURA Y ESCRITURA***************************************/
//Leer matriz desde archivo
void Read_Matrix(const char* File_name, double** A, int* row, int* col)
{
	FILE* Archivo_in;

	//Abrir archivo	y verificar si el archivo se abrio correctamente
	if((Archivo_in = fopen (File_name, "r"))==NULL)
	{
		printf("Nombre no valido\n");
	}
	else
	{
		//Leer las dimensiones de la matriz			
		fscanf(Archivo_in, "%d %d", row, col);	
		
		//Limpiar y solicitar memoria para la matriz
		*A = (double*)malloc((*row)*(*col)*sizeof(double));
		
		//Leer los coeficientes de la matriz		
		for(int i=0;i<(*row);i++)
		{
			for(int j=0;j<(*col);j++)
			{
				fscanf(Archivo_in,"%lf",(*A+i*(*col)+j));
			}
		}	
		//Cerrar archivo		
		fclose(Archivo_in);		
	}
}

//Guardar matriz a un archivo
void Save_Matrix(const char* File_name, const double* A, const int row, const int col)
{
	FILE* Archivo_out;
	
	//Crear archivo	y verificar si el archivo se creo correctamente
	if((Archivo_out = fopen (File_name, "w+"))==NULL)
	{
		printf("El archivo no se pudo crear\n");
	}
	else
	{
		
		//Guardar en el archivo las dimensiones
		fprintf(Archivo_out,"%d %d\n",row, col);
	
		//Guardar en el archivo los coeficientes de la matriz		
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				fprintf(Archivo_out,"%lf",*(A+i*col+j));
				
				if(j!=col-1)			
			  	 fprintf(Archivo_out," ");
				
			}
			
			if(i!=row-1)			
			  fprintf(Archivo_out,"\n");
		}	
		
		//Cerrar archivo		
		fclose(Archivo_out);		
	}
}


//Imprimir en pantalla una matrix
void Print_Matrix(const double* A, const int row, const int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%f ",*(A+i*col+j));
		}
		printf("\n");
	}
}

//Leer vector desde archivo
void Read_Vector(const char* File_name, double** A, int* row)
{
	FILE* Archivo_in;

	//Abrir archivo	y verificar si el archivo se abrio correctamente
	if((Archivo_in = fopen (File_name, "r"))==NULL)
	{
		printf("Nombre no valido\n");
	}
	else
	{
		//Leer las dimensiones de la matriz			
		fscanf(Archivo_in, "%d", row);	
		
		//Limpiar y solicitar memoria para la matriz
		*A = (double*)malloc((*row)*sizeof(double));
		
		//Leer los coeficientes de la matriz		
		for(int i=0;i<(*row);i++)
		{
			fscanf(Archivo_in,"%lf",(*A+i));
		}	
		//Cerrar archivo		
		fclose(Archivo_in);		
	}
}


//Guardar vector a un archivo
void Save_Vector(const char* File_name, const double* A, const int row)
{
	FILE* Archivo_out;
	
	//Crear archivo	y verificar si el archivo se creo correctamente
	if((Archivo_out = fopen (File_name, "w+"))==NULL)
	{
		printf("El archivo no se pudo crear\n");
	}
	else
	{
		//Guardar en el archivo las dimensiones
		fprintf(Archivo_out,"%d\n",row);
	
		//Guardar en el archivo los coeficientes de la matriz		
		for(int i=0;i<row;i++)
		{
			fprintf(Archivo_out,"%lf",*(A+i));
				
			if(i!=row-1)			
			  fprintf(Archivo_out,"\n");
		}	
		
		//Cerrar archivo		
		fclose(Archivo_out);		
	}
}

//Imprimir vector en pantalla
void Print_Vector(const double* A, const int row)
{
	for(int i=0;i<row;i++)
	{
		printf("%f\n",*(A+i));
	}
}
/***************************************************************************************************/
// clang -o main main.c
// ./main Matriz_A.txt
int main(int argc, char *argv[])
{
	/*
	// Vector
	double* b =NULL;
	int row_b;

	Read_Vector("Vector_b.txt", &b, &row_b);
	Print_Vector(b, row_b);
	Save_Vector( "Vector_c.txt", b, row_b );
	
	free(b);
	*/
	printf("argc: %d\n", argc );
	printf("argv[0]: %s \n", argv[0]);
	printf("argv[1]: %s \n", argv[1]);

	
	// Matriz
	double* A =NULL;
	int row_A;
	int col_A;
	Read_Matrix(argv[1], &A, &row_A, &col_A);
	Print_Matrix(A, row_A, col_A);
	//Save_Matrix("Matriz_C.txt", A, row_A, col_A );
	

	free(A);
	

	return 0;
}