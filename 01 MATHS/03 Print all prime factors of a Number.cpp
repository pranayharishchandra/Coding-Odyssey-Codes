#include <vector>  
#include <cmath> 
using namespace std;

vector<int> AllPrimeFactors(int N) {
    vector<int> ans;  // Vector to store prime factors of N
    
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            ans.push_back(i);  
            // Continue dividing N by i until it's no longer divisible
            while (N % i == 0) {
                N = N / i;
            }
        }
    }
    
    // If N is not 1 after the loop, it means N itself is a prime factor
    if (N != 1)
        ans.push_back(N);  // Add N to the prime factors list
    return ans;  // Return the list of prime factors
}
