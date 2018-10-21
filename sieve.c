#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sieve.h"

int sieve(int targetPrime)
{
  int num_buckets = targetPrime * log(targetPrime)  * 1.5 + 1;
  short * buckets = (short *) malloc(num_buckets * sizeof(short));

  for (int i = 0; i < num_buckets; i++)
  {
    if ( !buckets[i] )
    {
      buckets[i] = 2;
    }
  }

  int latest_prime = 3;
  int num_primes = 2;

  while ( num_primes < targetPrime )
  {
    int multiplier = 3;
    
    while ( multiplier * latest_prime < num_buckets )
    {
      if ( buckets[ multiplier * latest_prime ] )
      {
        buckets[ multiplier * latest_prime ] = 0;
      }

      multiplier += 2;
    }

    int new_prime = latest_prime + 2;

    while ( new_prime < num_buckets && buckets[ new_prime ] == 0 )
    {
      new_prime += 2;
    }

    latest_prime = new_prime;
    num_primes += 1;
  }

  return latest_prime;
}
