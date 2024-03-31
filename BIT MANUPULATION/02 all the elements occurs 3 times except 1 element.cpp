#include <vector>
#include <iostream>


// BRUTE - TC: O(32 x n) and a space complexity of O(1).
int singleNumber(std::vector<int>& nums) {
    int result = 0;
    
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        // for each bit i:(0 to 31), 
        // counting set (i)th set bits of each element j:(0 to n-1) 
        for (int j = 0; j < nums.size(); ++j) 
            if ((nums[j] >> i) & 1) 
                sum++;
        

        if (sum %= 3 != 0) 
            result |= (1 << i);
        
    }
    return result;
}



// OPTIMAL - This algorithm has a time complexity of O(n) and a space complexity of O(1).
int singleNumber(std::vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}

int main() {
    std::vector<int> nums = {2, 2, 3, 2};
    std::cout << "The element that occurs only once: " << singleNumber(nums) << std::endl;
    return 0;
}
