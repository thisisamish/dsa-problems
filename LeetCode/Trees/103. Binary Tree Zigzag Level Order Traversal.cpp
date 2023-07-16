// Written By - Amish Verma (@thisisamish)
// TC and SC both are O(n)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        bool flag = false; // flag set means l -> r, reset means r -> l
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> level(s);

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (flag) {
                    level[s - 1 - i] = node->val;
                } else {
                    level[i] = node->val;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            flag = !flag;
            ans.push_back(level);
        }

        return ans;
    }
};