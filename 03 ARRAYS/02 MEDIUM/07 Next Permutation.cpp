#include <vector>
#include <iostream>
using namespace std;


/** BRUTE : all permuatations code - cha
Time Complexity: O(N * N!) Note that there are N! permutations 
and it requires O(N) time to print a permutation.
Auxiliary Space: O(R – L)
 */

void permute(string& a, int l, int r, vector<string> allPermutations) 
{ 
    // Base case 
    if (l == r) 
         allPermutations.push_back(a);
    else { 
        // Permutations made 
        for (int i = l; i <= r; i++) { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l + 1, r, allPermutations); 
  
            // backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 
  

string nextPermutation(string str) { 
    int n = str.size(); 

    vector<string> allPermutations;
    // Function call 
    permute(str, 0, n - 1, allPermutations); 

    sort(allPermutations.begin(), allPermutations.end());

    for (int i=1; i<allPermutations.size(); i++) {
      if (allPermutations[i-1] == str) 
        return allPermutations[i];
    }

    // if no next permutation possible - reverse and reurn
    return allPermutations[0];
} 


/** OPTIMAL : STL (using in-built function of C++)
Time Complexity: O(3N), where N = size of the given array

Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).

Explaination: 
  std::next_permutation is called repeatedly inside a loop to generate all
  possible permutations of the vector vec. Each time it's called, it rearranges the elements
  in vec to the next lexicographically greater permutation. 
  The loop continues until std::next_permutation returns false, 
  indicating that there are no more permutations to generate.
*/


#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3};

    // Generate permutations
    do {
        for (int i : vec) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(vec.begin(), vec.end()));

    return 0;
}

/** OPTIMAL : STL internal: next_permutation: working (using in-built function of C++)
Time Complexity: O(3N), where N = size of the given array

Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).
 */


class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size(); // size of the array.

        // Step 1: Find the break point:
        int ind = -1; // break point
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                // index i is the break point
                ind = i;
                break;
            }
        }

        // case 1: corner case: If break point does not exist:
        if (ind == -1) {
            // reverse the whole array:
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[ind]:

        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 3: reverse the right half:
        reverse(A.begin() + ind + 1, A.end());
    }
};