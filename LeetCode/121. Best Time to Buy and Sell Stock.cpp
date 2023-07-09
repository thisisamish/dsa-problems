// Author : Amish Verma (@thisisamish)
// Two Pointers
// TC - O(n)
// SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, maxProfit = 0;

        while (r < prices.size()) {
            if (prices[l] >= prices[r]) {
                l = r;
            }
            else {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            }
            r++;
        }
        
        return maxProfit;
    }
};