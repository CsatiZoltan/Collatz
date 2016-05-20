#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

//void writeToFile(int* result, long nNumber, char* filename);
//int collatz(long n);

int main(int argc, char* argv[])
{
	int nNumber;
	if (argc == 1)
		nNumber = 10000;
	else
		nNumber = atoll(argv[1]);

   /* Loop through some natural numbers */
   long iNumber;
   int* iter = malloc(nNumber*sizeof(int));
   #pragma omp parallel for
   for (iNumber=1; iNumber<=nNumber; iNumber++)
   {
      iter[iNumber-1] = collatz(iNumber);
   }
   writeToFile(iter, nNumber, "result.txt");   
   free(iter);
}