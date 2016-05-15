# Collatz
Parallel implementation of the Collatz conjecture

## Collatz conjecture
The famous [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) states that if we take a positive integer *n* and divide it by 2 if *n* is even or multiply it by 3 and add 1 if it is odd, then we eventually reach 1.

## Implementation
The program gives the number of steps needed to reach 1 for all integers from 1 to *n*. Two versions will be available, a serial and a parallel version (up to now, only the parallel one is ready).

### Serial
The serial version writes the results to file as soon as the number of steps are calculated for a natural number. Therefore, only the current value must be stored, so the memory requirement is very low.

### Parallel
The parallelization is done by [OpenMP](www.openmp.org) just by including

    #pragma omp parallel for

Since it is a pragma, if the compiler does not recognize it, it is just excluded and the program will run serial.
Since we cannot write to file parallelly (the threads do not process the numbers in order), the computation and the file writing is separated for the parallel version. It has the further advantage that the code becomes modular, but the drawback is that the calculated values must be stored in an array. 

## Usage
The serial version needs a C89 capable C compiler. An executable is provided for Windows, compiled with [tcc](http://bellard.org/tcc/). The parallel version needs a compiler which implements OpenMP (e.g. Visual Studion in Windows, GCC on Linux and Intel's compiler on both Windows and Linux).

## Measurements
