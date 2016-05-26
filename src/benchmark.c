#include <stdio.h>
#include "collatz.h"


/* Tests the scalability of OpenMP by performing the calculations 
   on different number of threads */
double* benchmark(int startNumber, int endNumber)
{
	/* Print the available number of threads */
	int nThreads;
	#pragma omp parallel
	nThreads = omp_get_num_threads();
	printf("Number of available threads: %d\n", nThreads);

	/* Run the test */
	int iThread;
	double timeStart, timeEnd;
	int nNumbers = endNumber - startNumber + 1;
	double* timings = malloc(nThreads * sizeof(double));;
	int* iter = malloc(nNumbers*sizeof(int));
	for (iThread = 1; iThread <= nThreads; iThread++)
	{
		omp_set_num_threads(iThread);
		printf("Running the calculation on %d threads ...\n", iThread);
		timeStart = omp_get_wtime();
		collatz(startNumber, endNumber, iter, iThread);
		timeEnd = omp_get_wtime() - timeStart;
		printf("  Calculation finished in %lf seconds.\n", timeEnd);
		timings[iThread - 1] = timeEnd;
	}
	free(iter);
	return timings;
}

