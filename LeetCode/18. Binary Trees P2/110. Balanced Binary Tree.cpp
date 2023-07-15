// Written By - Amish Verma (@thisisamish)
// TC - O(n), SC - O(n)

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
private:
    int helper(TreeNode* root) {
        if (root == NULL) return 0;

       int l = helper(root->left);
       if (l == -1) return -1;
       int r = helper(root->right);
       if (r == -1) return -1;
       if (abs(l - r) > 1) return -1;

       return 1 + max(l, r); 
    }

public:
    bool isBalanced(TreeNode* root) {
       return helper(root) != -1;
    }
};