#include <stdio.h>
#include "collatz.h"
#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif


/* Tests the scalability of OpenMP by performing the calculations 
   on different number of threads */
double* benchmark(long nNumber)
{
	/* Print the available number of threads */
	int nThreads;
	#pragma omp parallel
	nThreads = omp_get_num_threads();
	printf("Number of available threads: %d\n", nThreads);

	/* Run the test */
	int iThread;
	double timeStart, timeEnd;
	double* timings = malloc(nThreads * sizeof(double));;
	int* iter = malloc(nNumber*sizeof(int));
	for (iThread = 1; iThread <= nThreads; iThread++)
	{
		omp_set_num_threads(iThread);
		printf("Running the calculation on %d threads ...\n", iThread);
		timeStart = omp_get_wtime();
		collatz(nNumber, iter, iThread);
		timeEnd = omp_get_wtime() - timeStart;
		printf("  Calculation finished in %lf seconds.\n", timeEnd);
		timings[iThread - 1] = timeEnd;
	}
	return timings;
}

