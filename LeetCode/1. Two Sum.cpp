// Author : Amish Verma (@thisisamish)
// Hashmap
// TC - O(n)
// SC - O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // num_added_to_currNum_to_make_target : index_of_currNum
        unordered_map<int, int> mapping;

        for (int i = 0; i < nums.size(); i++) {
            if (mapping.find(nums[i]) != mapping.end()) {
                return {mapping[nums[i]], i};
            }
            mapping[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};