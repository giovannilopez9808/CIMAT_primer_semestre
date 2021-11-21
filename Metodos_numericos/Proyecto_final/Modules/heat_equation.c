#include "heat_equation.h"

/*
  Purpose:
    F returns the right hand side of the heat equation.

  Parameters:

    Input, double A, B, the left and right endpoints.

    Input, double T0, the initial time.

    Input, double T, the current time.

    Input, int N, the number of points.

    Input, double X[N], the current spatial positions.

    Output, double VALUE[N], the prescribed value of U(X(:),T0).
*/
void f(double a, double b, double t0, double t, int n, double x[],
       double value[])
{
  (void)a;
  (void)b;
  (void)t0;
  (void)t;
  (void)n;
  (void)x;
  int i;

  for (i = 0; i < n; i++)
  {
    value[i] = 0.0;
  }
  return;
}

/*
  Purpose:

    R83_NP_FA factors a R83 system without pivoting.

  Discussion:

    The R83 storage format is used for a tridiagonal matrix.
    The superdiagonal is stored in entries (1,2:N), the diagonal in
    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
    original matrix is "collapsed" vertically into the array.

    Because this routine does not use pivoting, it can fail even when
    the matrix is not singular, and it is liable to make larger
    errors.

    R83_NP_FA and R83_NP_SL may be preferable to the corresponding
    LINPACK routine SGTSL for tridiagonal systems, which factors and solves
    in one step, and does not save the factorization.

  Example:

    Here is how a R83 matrix of order 5 would be stored:

       *  A12 A23 A34 A45
      A11 A22 A33 A44 A55
      A21 A32 A43 A54  *
  Parameters:

    Input, int N, the order of the matrix.
    N must be at least 2.

    Input/output, double A[3*N].
    On input, the tridiagonal matrix.  On output, factorization information.

    Output, int R83_NP_FA, singularity flag.
    0, no singularity detected.
    nonzero, the factorization failed on the INFO-th step.
*/
int r83_np_fa(int n, double a[])

{
  int i;

  for (i = 1; i <= n - 1; i++)
  {
    if (a[1 + (i - 1) * 3] == 0.0)
    {
      printf("\n");
      printf("R83_NP_FA - Fatal error!\n");
      printf("  Zero pivot on step %d\n", i);
      return i;
    }
    /*
      Store the multiplier in L.
    */
    a[2 + (i - 1) * 3] = a[2 + (i - 1) * 3] / a[1 + (i - 1) * 3];
    /*
      Modify the diagonal entry in the next column.
    */
    a[1 + i * 3] = a[1 + i * 3] - a[2 + (i - 1) * 3] * a[0 + i * 3];
  }

  if (a[1 + (n - 1) * 3] == 0.0)
  {
    printf("\n");
    printf("R83_NP_FA - Fatal error!\n");
    printf("  Zero pivot on step %d\n", n);
    return n;
  }

  return 0;
}

/*
  Purpose:
    R83_NP_SL solves a R83 system factored by R83_NP_FA.

  Discussion:
    The R83 storage format is used for a tridiagonal matrix.
    The superdiagonal is stored in entries (1,2:N), the diagonal in
    entries (2,1:N), and the subdiagonal in (3,1:N-1).  Thus, the
    original matrix is "collapsed" vertically into the array.

  Parameters:
    Input, int N, the order of the matrix.
    N must be at least 2.
    Input, double A_LU[3*N], the LU factors from R83_NP_FA.
    Input, double B[N], the right hand side of the linear system.
    On output, B contains the solution of the linear system.
    Input, int JOB, specifies the system to solve.
    0, solve A * x = b.
    nonzero, solve A' * x = b.

    Output, double R83_NP_SL[N], the solution of the linear system.
*/
double *r83_np_sl(int n, double a_lu[], double b[])
{
  double *x;
  x = (double *)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++)
  {
    x[i] = b[i];
  }
  // Solve L * Y = B.
  for (int i = 1; i < n; i++)
  {
    x[i] = x[i] - a_lu[2 + (i - 1) * 3] * x[i - 1];
  }
  //   Solve U * X = Y.
  for (int i = n; 1 <= i; i--)
  {
    x[i - 1] = x[i - 1] / a_lu[1 + (i - 1) * 3];
    if (1 < i)
    {
      x[i - 2] = x[i - 2] - a_lu[0 + (i - 1) * 3] * x[i - 1];
    }
  }
  return x;
}
/*
  Purpose:
    obtain_u0 returns the initial condition at the starting time.

  Parameters:

    Input, double A, B, the left and right endpoints
    Input, double T0, the initial time.
    Input, double T, the current time.
    Input, int N, the number of points where initial data is needed.
    Input, double X[N], the positions where initial data is needed.
    Output, double VALUE[N], the prescribed value of U(X,T0).
*/
void obtain_u0(double a, double b, double t0, int n, double x[], double value[])
{
  int i;
  (void)a;
  (void)b;
  (void)t0;
  (void)x;
  for (i = 0; i < n; i++)
  {
    value[i] = 100.0;
  }
  return;
}
/*
  Purpose:
    obtain_ua returns the Dirichlet boundary condition at the left endpoint.

  Parameters:
    Input, double A, B, the left and right endpoints
    Input, double T0, the initial time.
    Input, double T, the current time.
    Output, double obtain_ua, the prescribed value of U(A,T).
*/
double obtain_ua(double a, double b, double t0, double t)
{
  (void)a;
  (void)b;
  (void)t;
  (void)t0;
  double value;
  value = 20.0;
  return value;
}
/*
  Purpose:
    obtain_ub returns the Dirichlet boundary condition at the right endpoint.

  Parameters:
    Input, double A, B, the left and right endpoints
    Input, double T0, the initial time.
    Input, double T, the current time.
    Output, double obtain_ub, the prescribed value of U(B,T).
*/
double obtain_ub(double a, double b, double t0, double t)
{
  (void)a;
  (void)b;
  (void)t0;
  (void)t;
  double value;
  value = 2000.0;
  return value;
}
/*
  The matrix A does not change with time.  We can set it once,
  factor it once, and solve repeatedly.
*/
double *define_A_matrix(double k, double t_delta, double x_delta, int x_num)
{
  double w = k * t_delta / x_delta / x_delta;
  double *a = (double *)malloc(3 * x_num * sizeof(double));
  a[0 + 0 * 3] = 0.0;
  a[1 + 0 * 3] = 1.0;
  a[0 + 1 * 3] = 0.0;
  for (int i = 1; i < x_num - 1; i++)
  {
    a[2 + (i - 1) * 3] = -w;
    a[1 + i * 3] = 1.0 + 2.0 * w;
    a[0 + (i + 1) * 3] = -w;
  }
  a[2 + (x_num - 2) * 3] = 0.0;
  a[1 + (x_num - 1) * 3] = 1.0;
  a[2 + (x_num - 1) * 3] = 0.0;
  return a;
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

      U(X,T0) = obtain_u0(X)

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
void solve_system()
{
  double *a, *b, *fvec, *x, *t, *u;
  int i, j, x_num, t_num;
  char *u_file = "u.txt";
  double k, x_max, x_min, x_delta, t_max, t_min, t_delta;
  k = 5.0E-07;
  //   Set X values.
  x_min = 0.0;
  x_max = 0.3;
  x_num = 50;
  x_delta = (x_max - x_min) / (double)(x_num - 1);
  x = linspace(x_min, x_max, x_num);
  //   Set T values.
  t_min = 0.0;
  t_max = 100000.0;
  t_num = 101;
  t_delta = (t_max - t_min) / (double)(t_num - 1);
  t = linspace(t_min, t_max, t_num);
  b = (double *)malloc(x_num * sizeof(double));
  fvec = (double *)malloc(x_num * sizeof(double));
  // Set the initial data, for time T_MIN.
  u = (double *)malloc(x_num * t_num * sizeof(double));
  obtain_u0(x_min, x_max, t_min, x_num, x, u);
  a = define_A_matrix(k, t_delta, x_delta, x_num);
  // Factor the matrix.
  r83_np_fa(x_num, a);
  for (j = 0; j < t_num; j++)
  {
    //   Set the right hand side B.
    b[0] = obtain_ua(x_min, x_max, t_min, t[j]);
    f(x_min, x_max, t_min, t[j - 1], x_num, x, fvec);
    for (i = 1; i < x_num - 1; i++)
    {
      b[i] = u[i + (j - 1) * x_num] + t_delta * fvec[i];
    }
    b[x_num - 1] = obtain_ub(x_min, x_max, t_min, t[j]);
    free(fvec);
    fvec = r83_np_sl(x_num, a, b);
    for (i = 0; i < x_num; i++)
    {
      u[i + j * x_num] = fvec[i];
    }
  }
  r8mat_write(u_file, x_num, t_num, u);
  printf("\n");
  printf("  U data written to \"%s\".\n", u_file);
  free(a);
  free(b);
  free(fvec);
  free(t);
  free(u);
  free(x);
}