// Approach 1.1 : Sorting in ascending order
// TC is O(nlogn), SC is O(logn)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Approach 1.2 : Sorting in descending order
// TC is O(nlogn), SC is O(logn)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Approach 2.1 : Using maxheap (using make_heap())
// TC is O(n) for heapify + O(klogn) for popping k elements, SC is O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        while(k--) {
            pop_heap(nums.begin(), nums.end());
            if (k == 0) return nums.back();
            nums.pop_back();
        }
        return -1;
    }
};

// Approach 2.2 : Using maxheap (using priority_queue (does all the above used make_heap, pop_heap automatically))
// TC is O(n) for heapify + O(klogn) for popping k elements, SC is O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap (nums.begin(), nums.end());
        while (k--) {
            if (k == 0) return maxheap.top();
            maxheap.pop();
        }
        return -1;
    }
};

// Approach 3.1 : Using minheap (using comparator function in priority_queue)
// TC is O(nlogk) because minheap is always of k size and we iterate over nums, SC is O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (auto& num : nums) {
            minheap.push(num);
            if (minheap.size() > k) minheap.pop();
        }
        return minheap.top();
    }
};

// Approach 3.2 : Using minheap (without comparator function in priority_queue)
// TC is O(nlogk) because minheap is always of k size and we iterate over nums, SC is O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minheap;
        for (auto& num : nums) {
            minheap.push(-num);
            if (minheap.size() > k) minheap.pop();
        }
        return -minheap.top();
    }
};

// Approach 4 : Using quickselect
// 

