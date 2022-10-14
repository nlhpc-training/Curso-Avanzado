#include <stdio.h>
#include <math.h>
#include <mpi.h>

double fabs(double);

double f(double a) {
  return (4.0 / (1.0 + a * a));
}

int main(int argc, char *argv[]) {
  int  myid, numprocs;
  long unsigned i, n, nLocal;
  double PI25DT = 3.141592653589793238462643;
  double mypi, pi, h, sum, x, eTime, sTime, pTime;
  int source, dest, tag = 100;
  MPI_Status status;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
 
  sTime = MPI_Wtime();

  if (myid == 0)
    printf("Hay %d procesos en ejecución\n", numprocs);

  n = 10000000000;
  h = 1.0 / (double) n;
  sum = 0.0; // Suma de intervalos
  nLocal = (long unsigned) n / numprocs;

  for (i = myid*nLocal+1; i <= myid*nLocal+nLocal; i++) {
    x = h * ((double)i - 0.5);
    sum += f(x);
  }

  mypi = h * sum;
  //printf("Processor: %d, mypi: %.16f\n", myid, mypi);
  eTime = MPI_Wtime();
  pTime = fabs(eTime - sTime);

  if(myid == 0) {
    pi = mypi;
    for (i = 1; i < numprocs; i++) {
      source = i;        // Recibe resultados del resto de procesos 
      MPI_Recv(&mypi, 1, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status);
      pi += mypi;
    }
    printf("Pi es aproximadamente %.16f, el error cometido es %.16f\n", pi, fabs(pi - PI25DT));
    printf("Tiempo de ejecución: %f segundos\n",pTime);
  } else {
    dest = 0;
    // Envía cálculo local al proceso 0  
    MPI_Send(&mypi, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }

  MPI_Finalize();
}
