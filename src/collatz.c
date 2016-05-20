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