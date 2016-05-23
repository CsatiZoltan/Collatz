#include <stdio.h>
#include <stdlib.h>
#include "collatz.h"
#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

void writeToFile(int* result, long nNumber, char* filename);
void benchmark(long n);

/* Interface for the computational routine and the file handling */
int main(int argc, char* argv[])
{
	int nNumber;
	if (argc == 1)
		nNumber = 10000;
	else
		nNumber = atoll(argv[1]);

	benchmark(nNumber);
   //long iNumber;
   //int* iter = malloc(nNumber*sizeof(int));
   //writeToFile(iter, nNumber, "result.txt");   
   //free(iter);
}