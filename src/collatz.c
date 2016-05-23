#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif
#include "collatz.h"

void collatz(long n, int* iter, int nThreads)
{
	long i;
	int isodd; /* 1 if n is odd, 0 if even */
	#pragma omp parallel for
	for (i = 1; i <= n; i++)
	{
		omp_set_num_threads(nThreads);
		while(n > 1)
		{
			isodd = n%2;
			if (isodd)
				n = 3*n+1;
			else
				n/=2;
			i++;
		}
		iter[i - 1] = i;
	}
}