// TC is O(n^2)?, SC is O(n^2)?

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if (numRows <= 0) return res;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) row.push_back(1);
                else row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res.push_back(row);
        }

        return res;
    }
};