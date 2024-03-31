#include <vector>
#include <iostream>

// 6 -> 0000,110   ->1s->   1111,001  ->2s->  1111,010
//-6 -> 1111,010
// 6 & -6 = 0000,110 ^ 1111,010 = 0000,010
// 6 & -6 = 0000,010 => 2

// result1, result2 - one of them will always give 0 
// and other not 0 when xor with rightmostSetBit

std::pair<int, int> findTwoUnique(std::vector<int>& nums) {
    // Find the XOR of all elements
    int xorResult = 0;
    for (int num : nums) 
        xorResult ^= num;
    

    // Find the rightmost set bit in xorResult
    int rightmostSetBit = xorResult & (-xorResult);

    int result1 = 0, result2 = 0;

    // Partition the numbers into two groups based on rightmost set bit
    for (int num : nums) {
        if (num & rightmostSetBit) 
            result1 ^= num; // doing XOR because we want to eleminate the numbers occuring 2 times
        else 
            result2 ^= num; // XOR all numbers with this bit not set
        
    }

    return {result1, result2};
}

int main() {
    std::vector<int> nums = {1, 2, 3, 2, 1, 4};
    auto uniquePair = findTwoUnique(nums);
    std::cout << "Unique elements are: " << uniquePair.first << " and " << uniquePair.second << std::endl;
    return 0;
}


/** DRY RUN : {2, 4}

1. Initialize nums with values {2, 4}.
2. The function findTwoUnique is called with nums.
3. xorResult is initialized to 0.
4. Iterate through nums:
   - For num = 2:
     - xorResult ^= 2, so xorResult becomes 2.
   - For num = 4:
     - xorResult ^= 4, so xorResult becomes 6.
5. Calculate the rightmostSetBit:
   - xorResult is 6 in binary 110.
   - -xorResult is -6 in binary ...111111111111010.
   - rightmostSetBit = xorResult & (-xorResult), so rightmostSetBit becomes 2 (010).
6. Initialize result1 and result2 to 0.
7. Iterate through nums again:
   - For num = 2:
     - num & rightmostSetBit is 2 & 2, so it enters the if block.
     - result1 ^= 2, so result1 becomes 2.
   - For num = 4:
     - num & rightmostSetBit is 4 & 2, so it does not enter the if block.
     - result2 ^= 4, so result2 becomes 4.
8. Return {result1, result2} which is {2, 4}.

So, the output of the code will be:


Unique elements are: 2 and 4


The code identifies the unique elements in the vector nums, which are 2 and 4, and returns them as a pair.
 */