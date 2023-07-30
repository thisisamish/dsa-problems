// Approach 1 : Using hashmap + maxheap
// TC is O(nlogn), SC is O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> maxHeap;
        vector<int> res;

        for (int& num : nums) {
            m[num]++;
        }
        for (auto& el : m) {
            maxHeap.push({el.second, el.first});
        }

        while (k-- && !maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
};

// Approach 2 : Using hashmap + modified bucket sort algorithm
// TC is O(n), SC is O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;

        for (int& num : nums) {
            m[num]++;
        }
        for (auto& el : m) {
            bucket[el.second].push_back(el.first);
        }

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int& el : bucket[i]) {
                if (res.size() >= k) return res;
                res.push_back(el);
            }
        }
        
        return res;
    }
};