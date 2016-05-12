# Collatz
Parallel version of the Collatz conjecture

## Collatz conjecture
The famous [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) states that if we take a positive integer *n* and divide it by 2 if *n* is even or multiply it by 3 and add 1 if it is odd, then we eventually reach 1.

## Implementation
The program gives the number of steps needed to reach 1 for all integers from 1 to *n*. Two versions will be available, a serial and a parallel version (up to now, only the serial one is ready).

## Usage
The serial version needs a C89 capable C compiler. An executable is provided for Windows, compiled with [tcc](http://bellard.org/tcc/).
