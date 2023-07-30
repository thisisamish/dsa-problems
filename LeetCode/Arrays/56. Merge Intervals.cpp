// Approach 1 : Sort by start-time and merge
// TC is O(nlogn), SC (sort space) is O(logn)

// My code

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> currInterval = intervals[0];

        for (auto& interval : intervals) {
            if (interval[0] <= currInterval[1]) {
                currInterval[1] = max(currInterval[1], interval[1]);
            } else {
                res.push_back(currInterval);
                currInterval = interval;
            }
        }
        res.push_back(currInterval);

        return res;
    }
};

// LeetCode's more elegant code

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for (auto& interval : intervals) {
            if (res.empty() || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};

// Approach 2 : Using connected components concept (idk i didn't even try to understand it
// but it is available on LC Editorial so you can check it out if you want)