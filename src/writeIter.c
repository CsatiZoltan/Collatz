#include <stdio.h>
#include <stdlib.h>

/* Write Collatz iteration results to file */
void writeIter(int* result, int startNumber, int endNumber, char* filename)
{
   /* Open a text file where we save the results */
   FILE *fp;
   fp = fopen(filename,"w+");
   if (fp==NULL)
		printf("File opening was not successful.");

   /* Create the header */
   fprintf(fp, "  Number of steps\n\n");

	/* Write the results */
	int iNumber;
   for(iNumber=startNumber; iNumber <= endNumber; iNumber++)
		fprintf(fp, "  %d\n", result[iNumber-startNumber]);
	fclose(fp);
}