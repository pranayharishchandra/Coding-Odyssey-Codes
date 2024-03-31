#include <vector>
#include <iostream>
using namespace std;

/*Approach
The Sieve of Eratosthenes is a popular algorithm used to find all 
prime numbers up to a specified integer n. 
It works by iteratively marking the multiples of each prime number as composite (not prime). 


Here's how the algorithm works:

Create a boolean array isPrime[] of size n+1, initialized to true.
Iterate through numbers from 2 to the square root of n:
If isPrime[i] is true (i.e., i is prime), 
==> mark all multiples of i as composite by setting isPrime[j] to false, 
where j = i*i to n, with a step of i.

After the loop, all isPrime[i] that are still true represent prime numbers.
*/

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // for marking the prime numbers
    vector<int> primes;                // for returning the answer

    for (int p = 2; p * p <= n; ++p) 
        if (isPrime[p]) 
            for (int i = p * p; i <= n; i += p) 
                isPrime[i] = false; // Mark multiples of prime numbers as composite

    // Store prime numbers
    for (int p = 2; p <= n; ++p) 
        if (isPrime[p]) 
            primes.push_back(p);
        
    return primes;
}
