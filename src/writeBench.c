#include <stdio.h>

/* Write Collatz iteration results to file */
void writeBench(double* timings, int maxThreads, int startNumber, int endNumber, char* filename)
{
	/* Open a text file where we save the results */
	FILE *fp;
	fp = fopen(filename, "w+");
	if (fp == NULL)
		printf("File opening was not successful.");

	/* Create the header */
	fprintf(fp, "Benchmark results\n\n");
	fprintf(fp, "Testing on numbers from %d to %d.\n\n", startNumber, endNumber);
	fprintf(fp, "Number of threads   Elapsed time (s)  Speedup\n\n");

	/* Write the results */
	int iThread;
	for (iThread = 1; iThread <= maxThreads; iThread++)
		fprintf(fp, "        %d              %lf        %.2lf\n", iThread, timings[iThread - 1], timings[0]/ timings[iThread - 1]);
	fclose(fp);
}