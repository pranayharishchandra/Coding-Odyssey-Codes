#include <vector>
#include <iostream>

using namespace std;

/* BRUGE AND BETTER: refer question : 01 Longest Subarray with Sum K*/
/** Optimal
Time Complexity: O(N), N = size of the given array.
Reason: We are using a single loop that runs for N times.

Space Complexity: O(1) as No extra data structures are used for computation.
 */

int maxProduct(vector<int> &arr) {
    int n = arr.size(); 

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        // turn 0 to 1, since product with 0 is 0
        if (pre == 0)  pre  = 1;
        if (suff == 0) suff = 1;

        pre  *= arr[i];
        suff *= arr[n - i - 1];
        ans   = max(ans, max(pre, suff));
    }
    return ans;
}
