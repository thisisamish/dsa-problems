// Author : Amish Verma (@thisisamish)
// There are 7 methods to solve this. The first 4 won't pass on LeetCode due to constraints.

// Mtd 1 : Sorting
// Won't pass on LeetCode as it modifies the array and doesn't use constant space
// TC - O(nlogn)
// SC - The space complexity of the sorting algorithm depends on the implementation of each programming language:
// In Java, Arrays.sort() for primitives is implemented using a variant of the Quick Sort algorithm, which has a space complexity of O(log⁡n)
// In C++, the sort() function provided by STL uses a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of O(log⁡n)
// In Python, the sort() function is implemented using the Timsort algorithm, which has a worst-case space complexity of O(n)

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

// Mtd 2 : Hashset
// Won't pass on LeetCode as it doesn't use constant space
// TC - O(n)
// SC - O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (auto& el : nums) {
            if (seen.count(el) == 1) {
                return el;
            }
            seen.insert(el);
        }

        return -1;
    }
};

// Mtd 3 : Negative Marking
// Won't pass on LeetCode as it temporarily modifies individual elements of the array
// TC - O(n)
// SC - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int curr = abs(nums[i]);
            if (nums[curr] < 0) {
                return curr;
            }
            nums[curr] *= -1;
        }

        return -1;

        // We can also make all the elements of the array back to positive before returning the answer.
        // That way we can show that we are mindful of the constraints.
    }
};

// Mtd 4 : 