#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "collatz.h"



/* Function declarations */
void printHelp();
void writeToFile(int* result, int nNumber, char* filename);
void benchmark(int startNumber, int endNumber);

/* Interface for the computational routine and the file handling */
int main(int argc, char* argv[])
{
	/* =========== Process command line arguments =========== */

	int i; /* iteration index */
	int append = 0; /* if append = 1 and the output file exists, append it instead of overwriting */
	int bench = 0; /* if benchmark = 1, do a benchmark */
	int nThreads = 1; /* number of threads to use */
	int inputRequired = 1; /* for some flags, (like -h, -v) input is not necessary */
	int arg; /* current input argument number */
	char flag; /* current options flag */
	char *flags = "abhov";
	char *flagRequireInputs = "ot"; /* those flags that require at least one additional input */
	char *flagInputs = "11"; /* required inputs for flags -o, in this order */
	char *flagIndex; /* position of flag in flagRequireInputs */
	char outputFileName[200];  /* output location */
	int startNumber = 1; /* first number to be checked */
	int endNumber = 10000; /* last number to be checked */

	if (argc == 1)
		printHelp();
	argv[argc] = "";

	for (arg = 1; argv[arg][0] == '-';) {
		/* If the current flag requires inputs, check if they are correct */
		flag = argv[arg++][1];
		if (flagIndex = strchr(flagRequireInputs, flag))
			for (i = 0; i < flagInputs[flagIndex - flagRequireInputs] - '0'; i++)
				if (!isalnum(argv[arg + i][0])) {
					fprintf(stderr, ("Non-alphanumerical argument to -%c\n"), flag);
					return -2;
				}
		/* Process the current flag */
		switch (flag) {
		case 'a':
			append = 1;
			break;
		case 'b':
			bench = 1;
			break;
		case 'o':
			strcpy(outputFileName, argv[arg++]);
			break;
		case 'h':
			printHelp();
			inputRequired = 0;
			break;
		case 't':
			nThreads = argv[arg++];
			break;
		case 'v':
			printf("version 1.0\n");
			inputRequired = 0;
			break;
		default:
			fprintf(stderr, ("Unknown option \"-%c\".\n"), flag);
			return -3;
		}
	}

	if (arg == argc) {
		if (inputRequired);	/* Do nothing */
		else
			return 0;
	}
	else if (arg + 1 == argc) /* ending number given */
		endNumber = atol(argv[arg++]);
	else if (arg + 2 == argc) { /* starting and ending number given */
		startNumber = atol(argv[arg++]);
		endNumber = atol(argv[arg++]);
	}
	else
		printf("");

	/* =========== Perform calculations =========== */

	if (bench==1)
		benchmark(startNumber, endNumber);
	else {
		int nNumbers = endNumber - startNumber + 1;
		int* iter = malloc(nNumbers*sizeof(int));
		omp_set_num_threads(nThreads);
		collatz(startNumber, endNumber, iter, nThreads);
		writeToFile(iter, nNumbers, "result.txt");
		free(iter);
	}
}



/* Print help message to screen either if it is directly asked with the -h flag or
if unexpected syntax is found */
void printHelp()
{
	printf("\nUsage:   Collatz [OPTIONS] startNumber endNumber\n\n");
	printf("\t OPTIONS\n");
	printf("\t -a: append the output file instead of overwriting it\n");
	printf("\t -b: write the benchmark results to file, not the iteration values\n");
	printf("\t -h: print this help message\n");
	printf("\t -o OUTPUT: save results to the OUTPUT location\n");
	printf("\t -v: program version\n\n");
}