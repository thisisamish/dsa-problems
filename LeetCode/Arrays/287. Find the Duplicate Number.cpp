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

// 3 : Using negative-marking
// TC is O(n), SC is O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            int curr = abs(nums[i]);
            if (nums[curr] < 0) {
                res = curr;
                break;
            }
            nums[curr] *= -1; // marking nums[i] as visited
        }

        // Restoring the array
        for (auto& n : nums) {
            n = abs(n);
        }
        
        return res;
    }
};

// 4.1 : Using the given array as hashmap (using recursion)
// TC is O(n), SC (stack size) is O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums[0] == nums[nums[0]]) {
            return nums[0];
        }
        swap(nums[0], nums[nums[0]]);
        return findDuplicate(nums);
    }
};

// 4.2 : Using the given array as hashmap (iterative solution)
// TC is O(n), SC is O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[nums[0]] != nums[0]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};