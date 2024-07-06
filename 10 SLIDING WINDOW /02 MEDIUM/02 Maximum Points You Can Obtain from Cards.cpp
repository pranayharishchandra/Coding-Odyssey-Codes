// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**APPROCH 
  since you have to pick exactly k cards
  so (n-k) cards will be left out after pickiung k cards
  as you can only pick the cards either from the start or the end or both
  this means you can only the skip the (n-k) cards contigious in between
  so you have to use sliding window in the (n-k) cards between making the smallest sum
  so you can reduce it from the total sum and you will get the max sum made by k cards
  
  Equation: req_max_sum = total_sum - n_k_cards_min_sum

*/
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int totalSum = 0;
    
    // Calculate the total sum of all cards
    for(int card : cardPoints)
        totalSum += card;
    
    int windowSize = n - k;
    int currentSum = 0;


    // Calculate the sum of the first window of size (n - k)
    for(int i = 0; i < windowSize; ++i)
        currentSum += cardPoints[i];
    
    int minSum = currentSum;

    // Slide the window and keep track of the minimum sum
    for(int i = windowSize; i < n; ++i) {
        currentSum += cardPoints[i] - cardPoints[i - windowSize];
        minSum = min(minSum, currentSum);
    }

    // The maximum points will be the total sum minus the minimum sum of the window
    return totalSum - minSum;
}
