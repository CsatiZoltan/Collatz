#include <stdio.h>
#include <stdlib.h>

void writeToFile(int* result, int nNumber, char* filename)
{
   /* Open a text file where we save the results */
   FILE *fp;
   fp = fopen(filename,"w+");
   if (fp==NULL)
		printf("File opening was not successful.");

   /* Create the header */
   fprintf(fp, "  Number of steps\n\n");

	/* Write the results */
	long iNumber;
   for(iNumber=1; iNumber <= nNumber; iNumber++)
		fprintf(fp, "  %d\n", result[iNumber-1]);
	fclose(fp);
}