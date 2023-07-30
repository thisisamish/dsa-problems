// Kadane's algorithm
// TC is O(n), SC is O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            res = max(res, currSum);
            currSum = max(currSum, 0);
        }
        return res;
    }
};