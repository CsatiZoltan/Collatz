# Collatz
Parallel implementation of the Collatz conjecture

## Collatz conjecture
The famous [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) states that if we take a positive integer *n* and divide it by 2 if *n* is even or multiply it by 3 and add 1 if it is odd, then we eventually reach 1.

## Implementation
The program gives the number of steps needed to reach 1 for all integers from 1 to *n*. Two versions will be available, a serial and a parallel version (up to now, only the parallel one is ready).

### Serial
The serial version writes the results to file as soon as the number of steps are calculated for a natural number. Therefore, only the current value must be stored, so the memory requirement is very low. See the code in the [serial](https://github.com/CsatiZoltan/Collatz/tree/serial) branch.

### Parallel
The parallelization is done by [OpenMP](www.openmp.org) just by including

    #pragma omp parallel for

Since it is a pragma, if the compiler does not recognize it, it is just excluded and the program will run serial.
Since we cannot write to file parallelly (the threads do not process the numbers in order), the computation and the file writing is separated for the parallel version. It has the further advantage that the code becomes modular, but the drawback is that the calculated values must be stored in an array. As this is the default implementation, the [master](https://github.com/CsatiZoltan/Collatz/tree/master) branch contains it.

## Compilation
The serial version only needs a C89 capable C compiler. An executable is provided for Windows, compiled with [tcc](http://bellard.org/tcc/). The parallel version requires a compiler which implements OpenMP (e.g. Visual Studion in Windows, GCC on Linux and Intel's compiler on both Windows and Linux). On Windows with the Intel compiler, compile it as

    icl /Qopenmp /O3 main.c collatz.c benchmark.c writeBench.c -o Collatz.exe
    
On Windows with the Visual Studio compiler:

    cl /openmp /O2 main.c collatz.c benchmark.c writeIter.c writeBench.c /FeCollatz.exe

On Linux with GCC:

    gcc -fopenmp main.c collatz.c benchmark.c writeIter.c writeBench.c -o Collatz

## Usage
Open a command prompt in Windows or a terminal in Linux and set the number of threads you want to the program to run on. For it type

    set OMP_NUM_THREADS=num
    
or in some shells

    export OMP_NUM_THREADS=num
    
where *num* is a positive integer. If not set, the default number of threads will be used by OpenMP which is the number of hardware threads (called hyperthreads for Intel processors). After the threads are set, launch the program. For Windows, type

    Collatz n

to check the conjecture from 1 to *n* or just type the program name without an argument

    Collatz
   
to test it for the default bound, 10000. If the file writing was successful, the program will create a text file `result.txt` in the directory where the program is invoked from. This file contains the number of steps for each number from 1 to *n*.

## Measurements

