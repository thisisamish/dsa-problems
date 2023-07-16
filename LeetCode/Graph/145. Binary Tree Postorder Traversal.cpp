// Written By - Amish Verma (@thisisamish)
// Approach 1 : Recursion
// TC - O(n), SC - O(n) where n is number of nodes

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
    void helper(TreeNode* node, vector<int>& traversal) {
        if (!node) {
            return;
        }
        helper(node->left, traversal);
        helper(node->right, traversal);
        traversal.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        helper(root, traversal);
        return traversal;
    }
};