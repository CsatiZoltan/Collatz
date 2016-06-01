#include <stdio.h>
#include "collatz.h"


/* Tests the scalability of OpenMP by performing the calculations 
   on different number of threads */
void benchmark(int startNumber, int endNumber, int maxThreads, double* timings)
{
	printf("Number of available threads: %d\n", maxThreads);
	/* Run the test */
	int iThread;
	double timeStart, timeEnd;
	int nNumbers = endNumber - startNumber + 1;
	int* iter = malloc(nNumbers*sizeof(int));
	for (iThread = 1; iThread <= maxThreads; iThread++)
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
}

