#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int collatz(long n);

int main(int argc, char* argv[])
{
	int nNumber;
	if (argc == 1)
		nNumber = 1000000;
	else
		nNumber = atoll(argv[1]);
   /* Open a text file where we save the results */
   //FILE *fp;
   //fp = fopen("C:\\Programok\\Portable\\tcc\\collatz.txt","w+");
   /* Create the header */
   //fprintf(fp, "  Number\tTotal stopping time\n\n");
   /* Loop through some natural numbers */
   long iNumber;
   int iter;
   #pragma omp parallel for
   for(iNumber=1; iNumber<=nNumber; iNumber++)
   {
      iter = collatz(iNumber);
      //fprintf(fp, "  %ld\t\t%d\n", iNumber, iter);
   }
   /* Close the file */
   //fclose(fp);
}

int collatz(long n)
{
   int i = 0;
   int isodd; /* 1 if n is odd, 0 if even */
   while(n > 1)
   {
      isodd = n%2;
      if (isodd)
         n = 3*n+1;
      else
         n/=2;
      i++;
   }
   return i;
}