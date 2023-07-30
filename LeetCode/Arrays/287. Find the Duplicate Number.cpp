// 1 : Using Sort
// TC is O(nlogn), SC is O(logn)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }

        return -1;
    }
};

// 2 : Using hashset
// TC is O(n), SC is O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> unique;

        for (int i = 0; i < nums.size(); i++) {
            if (unique.find(nums[i]) != unique.end()) {
                return nums[i];
            }
            unique.insert(nums[i]);
        }

        return -1;
    }
};

//