#include <stdio.h>
#include <math.h>
#include <omp.h>

double fabs(double);

double f(double a) {
  return (4.0 / (1.0 + a * a));
}

int main(int argc, char *argv[]) {
  long int  n, i;
  double PI25DT = 3.141592653589793238462643;
  double pi, h, sum, x, eTime, sTime;

  n = 9999999999;
  h   = 1.0 / (double) n;
  sum = 0.0; // Suma de intervalos

  int iam =0, np = 1;
  #pragma omp parallel private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    if (iam == 0)
      printf("Hay %d hilos en ejecución\n",np);
  }

  sTime = omp_get_wtime();

  #pragma omp parallel for reduction(+:sum) private(x)
  for (i = 1; i <= n; i++) {
    x = h * ((double)i - 0.5);
    sum += f(x);
  }

  pi = h * sum;

  eTime = omp_get_wtime() - sTime;
  printf("Pi es aproximadamente %.16f, el error cometido es %.16f\n", pi, fabs(pi - PI25DT));
  printf("Tiempo de ejecución: %f segundos\n",eTime);
}