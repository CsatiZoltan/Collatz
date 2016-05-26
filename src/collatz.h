#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

void collatz(int startNumber, int endNumber, int* iter, int nThreads);