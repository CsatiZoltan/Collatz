#include <stdio.h>

void writeToFile(int* result, int nNumber, char* filename)
{
   /* Open a text file where we save the results */
   FILE *fp;
   fp = fopen(filename,"w+");
   if (fp==NULL)
     printf("File opening was not successful.");
   /* Create the header */
   fprintf(fp, "  Number of steps\n\n");
   long iNumber;
   for(iNumber=1; iNumber <= nNumber; iNumber++)
      fprintf(fp, "  %d\n", result[iNumber-1]);
   /* Close the file */
   fclose(fp);
}