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
    int preInd;
    unordered_map<int, int> inIndexOf;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        // l and r are pointers for preorder traversal
        // they are used to limit the left or right subtree
        // in the preorder traversal
        if (l <= r) {
            TreeNode* root = new TreeNode(preorder[preInd]);
            // inInd is the pointer in inorder traversal
            int inInd = inIndexOf[preorder[preInd]];
            preInd++;
            root->left = build(preorder, inorder, l, inInd - 1);
            root->right = build(preorder, inorder, inInd + 1, r);
            return root;
        }
        return NULL;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preInd is the pointer in preorder traversal
        preInd = 0;
        // clearing the map as it is declared as a global variable
        inIndexOf.clear();
        int n = preorder.size();

        // creating nodeVal : index map for inorder traversal
        for (int i = 0; i < n; i++) {
            inIndexOf[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n - 1);
    }
};