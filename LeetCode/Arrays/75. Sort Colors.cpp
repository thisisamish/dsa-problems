// Approach 1 : Count sort
// TC is O(n), SC is O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0;

        for (int& n : nums) {
            if (n == 0) zeros++;
            if (n == 1) ones++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeros) {
                nums[i] = 0;
                zeros--;
                continue;
            }
            if (ones) {
                nums[i] = 1;
                ones--;
                continue;
            }
            nums[i] = 2;
        }
    }
};

// Approach 2 : Two pointers/Three pointers/Dutch National Flag algorithm
// TC is O(n), SC is O(1)

class Solution {
    void swap(vector<int>& nums, int l , int r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }

public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int i = 0;

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums, i, l);
                l++;
            }
            if (nums[i] == 2) {
                swap(nums, i, r);
                r--;
                i--;
            }
            i++;
        }
    }
};
