#include <vector>  
#include <cmath> 
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;
        
        // long n_temp = (n<0)?  n * (-1): n ; 
        // above will give me error because -INT_MIN can't be handeled by (int)

        long n_temp = (n<0)? (long) n * (-1): n ;

        while (n_temp > 0) 
            if (n_temp % 2 == 0) 
                x = x * x,     
                n_temp /= 2;
            
            else 
                ans = ans * x, 
                n_temp--;
        

        // if power negative, 1/ans
        if (n < 0) 
            return (double)1 / ans;
        
        return ans;
    }
};

