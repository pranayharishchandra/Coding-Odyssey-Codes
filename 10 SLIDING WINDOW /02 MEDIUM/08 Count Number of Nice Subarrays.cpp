#include <vector>
using namespace std;

class Solution {
public: 
    int subArray(vector<int>& nums, int k) {
        int count = 0, ans = 0, start = 0, end = 0;  // Initialize variables
        int n     = nums.size();                     // Get the size of the input array


        for (int end = 0; end < n; end++) {

            if(nums[end] % 2 == 1)  // If the element at the end pointer is odd
            count++;                // Increment the count of odd numbers
            

            while(count > k) { // If the count of odd numbers exceeds k

                if(nums[start] % 2 == 1)  // If the element at the start pointer is odd
                count--;                  // Decrement the count of odd numbers
                

                start++;  // Move the start pointer to the right
            }
            ans += end - start + 1;  // Increment the answer by the length of the current subarray
            
        }
        return ans;  // Return the total count of subarrays
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Return the difference between subArray(nums, k) and subArray(nums, k - 1)
      return subArray(nums, k) - subArray(nums, k - 1); 
    }
};


