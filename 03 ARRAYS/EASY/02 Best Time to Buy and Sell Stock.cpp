/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock/*/

#include <vector>
using namespace std;

// TC: O(n) SC:O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int max_profit = 0;

        for (int price: prices) {
            left = min(left, price);
            int right = price;

            max_profit = max(max_profit, right-left);
        }

        return max_profit;
    }
};