// Both the approaches have the same TC and SC but interative one
// has a better SC because we aren't storing the whole traversal
// Approach 1 : DFS (recursive) inorder traversal
// TC is O(n), SC is O(n)

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
public:
    void dfs(vector<int>& traversal, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        dfs(traversal, node->left);
        traversal.push_back(node->val);
        dfs(traversal, node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> traversal;
        dfs(traversal, root);
        return traversal[k-1];
    }
};

// Iterative inorder traversal using stack
// TC is O(n), SC is O(n)

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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        int count = 0;
        while (curr || !s.empty()) {
            if (curr == NULL) {
                TreeNode* node = s.top();
                count++;
                if (count == k) return node->val;
                s.pop();
                curr = node->right;
            } else {
                s.push(curr);
                curr = curr->left;
            }
        }
        return -1;
    }
};
