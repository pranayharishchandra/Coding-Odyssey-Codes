//{ Driver Code Starts
#include <iostream>
#include <cmath>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false; // 0 and 1 are not prime
        }
        if (n <= 3) {
            return true; // 2 and 3 are prime
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false; // Numbers divisible by 2 or 3 are not prime
        }
        // Check divisibility by numbers of the form 6k +/- 1 up to sqrt(n)
        for (int i = 5; i <= sqrt(n); i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true; // If no divisors found, number is prime
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends