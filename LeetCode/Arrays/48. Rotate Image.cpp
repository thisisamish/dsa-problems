// Approach 1 : Naive
// TC is O(n^2), SC is O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));
        int row = 0;
        int col = n - 1;
        while (row < n) {
            for (int i = 0; i < n; i++) {
                res[i][col] = matrix[row][i];
            }
            row++;
            col--;
        }
        matrix = res;
    }
};

// Approach 2 : Swap rows from start and end then perform transpose
// TC is O(n^2), SC is O(1)

// Implementation 1 : Using while loop in transpose

class Solution {
    void swapRows(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n/2; i++) {
            swap(matrix[i], matrix[n - 1 - i]);
        }
    }

    void transposeMatrix(vector<vector<int>>& matrix, int n) {
        int row = 0;
        int col = 0;
        while (row < n) {
            for (int i = row; i < n; i++) {
                swap(matrix[row][i], matrix[i][col]);
            }
            row++;
            col++;
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        swapRows(matrix, n);
        transposeMatrix(matrix, n);
    }
};

// Implementation 2 : Using for loop in transpose

class Solution {
    void swapRows(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n/2; i++) {
            swap(matrix[i], matrix[n - 1 - i]);
        }
    }

    void transposeMatrix(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        swapRows(matrix, n);
        transposeMatrix(matrix, n);
    }
};

// Approach 3 : Transpose then reverse every row
// TC is O(n^2), SC is O(1)

class Solution {
    void reverseRows(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void transposeMatrix(vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transposeMatrix(matrix, n);
        reverseRows(matrix, n);
    }
};