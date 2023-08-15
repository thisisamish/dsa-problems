// Pure Binary Search
// TC is O(logmn), SC is O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, h = m * n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};

// Binary Search on each row
// TC is O(mlogn), SC is O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto row: matrix) {
            int l = 0, r = row.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (row[mid] == target) return true;
                if (row[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};

// Applying Binary Search twice (first to find the row, second to find the col)
// TC is O(logm + logn), SC is O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int outerSize = matrix.size();
        int innerSize = matrix[0].size();
        int start = 0;
        int end = outerSize - 1;
        int correctRow = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] <= target && matrix[mid][innerSize - 1] >= target)
                correctRow = mid;
            if (target > matrix[mid][innerSize - 1]) start = mid + 1;
            else end = mid - 1;
        }
        if (correctRow == -1) return false;
        start = 0;
        end = innerSize - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[correctRow][mid] == target) return true;
            if (matrix[correctRow][mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};