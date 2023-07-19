// Written by - Amish Verma (@thisisamish)
// TC is O(n) and SC is O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* helper(vector<int>& nums, int l, int h) {
        if (l <= h) {
            int m = l + (h - l) / 2;
            TreeNode* root = new TreeNode(nums[m]);
            root->left = helper(nums, l, m - 1);
            root->right = helper(nums, m + 1, h);
            return root;
        }
        return NULL;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};