#include "heat_equation.h"
/*
  Crea el el vector del lado derecho de la ecuacion de calor

  Parametros:
    Input, int n, numero de puntos.
    Input, double* vector, posiciones.
*/
void create_vector(double value, double *vector, int n)
{
  for (int i = 1; i < n - 1; i++)
  {
    vector[i] = value;
  }
}

void valid_obtain_factorization(double *matrix, int i)
{
  if (matrix[1 + (i - 1) * 3] == 0.0)
  {
    printf("\n");
    printf("==== obtain_factorization - Error ====\n");
    printf("====  Division entre cero %d ====\n", i);
    exit(1);
  }
}
/*
  Realiza la factorizacion de la matriz tridimensional

  Parametros:
  Input: int dimension, dimension de la matriz
  Input: double* matrix, matriz tridiagonal

*/
void obtain_factorization(int dimension, double *matrix)
{
  for (int i = 1; i < dimension; i++)
  {
    valid_obtain_factorization(matrix, i);
    // Store the multiplier in L.
    matrix[2 + (i - 1) * 3] = matrix[2 + (i - 1) * 3] / matrix[1 + (i - 1) * 3];
    // Modify the diagonal entry in the next column.
    matrix[1 + i * 3] = matrix[1 + i * 3] - matrix[2 + (i - 1) * 3] * matrix[0 + i * 3];
  }
  valid_obtain_factorization(matrix, dimension);
}

/*
  Resuelve el sistema de ecuaciones obtenido de la matriz de la funcion obtain_factorization

  Parametros:
    Input, int n, dimension de la matriz.
    Input, double* matrix, factorizacion LU de obtain_factorization.
    Input, double* vector, vector del lado izquierdo del sistema lienal.
    Output, double* solution, solucion del sistema de ecuaciones.
*/
double *solve_matrix(int n, double *matrix, double *vector)
{
  double *solution;
  solution = (double *)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++)
  {
    solution[i] = vector[i];
  }
  // Resuelve L * Y = B.
  for (int i = 1; i < n; i++)
  {
    solution[i] = solution[i] - matrix[2 + (i - 1) * 3] * solution[i - 1];
  }
  // Resuelve U * X = Y.
  for (int i = n; 1 <= i; i--)
  {
    solution[i - 1] = solution[i - 1] / matrix[1 + (i - 1) * 3];
    if (i > 1)
    {
      solution[i - 2] = solution[i - 2] - matrix[0 + (i - 1) * 3] * solution[i - 1];
    }
  }
  return solution;
}
/*
  Crea el estado inicial del sistema

  Parametros:
    Input, Parameters parameters, estructura que contiene valor del estado inicial
    Input, int n, numero de puntos.
    Input, double* vector, datos de cada posicion.
*/
void set_initial_state(Parameters parameters, double *vector, int n)
{
  for (int i = 0; i < n; i++)
  {
    vector[i] = parameters.u0;
  }
}
/*
  La matriz A no cambia en el tiempo
*/
double *define_A_matrix(double k, double t_delta, double x_delta, int x_num)
{
  // Definicion de w
  double w = k * t_delta / x_delta / x_delta;
  double *matrix = (double *)malloc(3 * x_num * sizeof(double));
  matrix[0] = 0.0;
  matrix[1] = 1.0;
  matrix[3] = 0.0;
  for (int i = 1; i < x_num - 1; i++)
  {
    matrix[2 + (i - 1) * 3] = -w;
    matrix[1 + i * 3] = 1.0 + 2.0 * w;
    matrix[0 + (i + 1) * 3] = -w;
  }
  matrix[2 + (x_num - 2) * 3] = 0.0;
  matrix[1 + (x_num - 1) * 3] = 1.0;
  matrix[2 + (x_num - 1) * 3] = 0.0;
  return matrix;
}
/*
  Purpose:
    MAIN is the main program for FD1D_HEAT_IMPLICIT.

  Discussion:
    FD1D_HEAT_IMPLICIT solves the 1D heat equation with an implicit method.

    This program solves

      dUdT - k * d2UdX2 = F(X,T)

    over the interval [A,B] with boundary conditions

      U(A,T) = obtain_ua(T),
      U(B,T) = obtain_ub(T),

    over the time interval [T0,T1] with initial conditions

      U(X,T0) = set_initial_state(X)

    The code uses the finite difference method to approximate the
    second derivative in space, and an implicit backward Euler approximation
    to the first derivative in time.

    The finite difference form can be written as

      U(X,T+dt) - U(X,T)                  ( U(X-dx,T) - 2 U(X,T) + U(X+dx,T) )
      ------------------  = F(X,T) + k *  ------------------------------------
               dt                                   dx * dx

    so that we have the following linear system for the values of U at time T+dt:

            -     k * dt / dx / dx   * U(X-dt,T+dt)
      + ( 1 + 2 * k * dt / dx / dx ) * U(X,   T+dt)
            -     k * dt / dx / dx   * U(X+dt,T+dt)
      =               dt             * F(X,   T+dt)
      +                                U(X,   T)
*/
void solve_system(Parameters Parametros)
{
  double *a, *b, *fvec, *x, *t, *u;
  int x_num, t_num;
  char *u_file = "u.txt";
  double k, x_max, x_min, x_delta, t_max, t_min, t_delta;
  k = Parametros.k;
  //   Set X values.
  x_min = Parametros.x_min;
  x_max = Parametros.x_max;
  x_num = Parametros.x_num;
  x_delta = (x_max - x_min) / (double)(x_num - 1);
  x = linspace(x_min, x_max, x_num);
  //   Set T values.
  t_min = Parametros.t_min;
  t_max = Parametros.t_max;
  t_num = Parametros.t_num;
  t_delta = (t_max - t_min) / (double)(t_num - 1);
  t = linspace(t_min, t_max, t_num);
  b = (double *)malloc(x_num * sizeof(double));
  fvec = (double *)malloc(x_num * sizeof(double));
  // Set the initial data, for time T_MIN.
  u = (double *)malloc(x_num * t_num * sizeof(double));
  set_initial_state(Parametros, u, x_num);
  a = define_A_matrix(k, t_delta, x_delta, x_num);
  // Factor the matrix.
  obtain_factorization(x_num, a);
  for (int i = 1; i < t_num; i++)
  {
    //   Set the right hand side B.
    b[0] = Parametros.ua;
    b[x_num - 1] = Parametros.ub;
    create_vector(1.0, fvec, x_num);
    for (int j = 1; j < x_num - 1; j++)
    {
      b[j] = u[j + (i - 1) * x_num] + t_delta * fvec[j];
    }
    free(fvec);
    fvec = solve_matrix(x_num, a, b);
    for (int j = 0; j < x_num; j++)
    {
      u[j + i * x_num] = fvec[j];
    }
  }
  write_results(u_file, x_num, t_num, u);
  free(a);
  free(b);
  free(fvec);
  free(t);
  free(u);
  free(x);
}
