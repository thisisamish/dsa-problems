// Written By - Amish Verma
// Approach 1 : Using level order traversal and maintaining a levels vector
// TC is O(n) and SC is O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        vector<vector<Node*>> levels;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<Node*> level;

            while (s--) {
                Node* node = q.front();
                q.pop();
                level.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levels.push_back(level);
        }

        for (int i = 0; i < levels.size(); i++) {
            for (int j = 0; j < levels[i].size(); j++) {
                if (j == levels[i].size() - 1) {
                    levels[i][j]->next = NULL;
                }
                else {
                    levels[i][j]->next = levels[i][j + 1];
                }
            }
        }

        return levels[0][0];
    }
};

// Approach 2 : Using level order tarversal but not keeping levels vector
// TC is O(n) and SC is O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            Node* prev = NULL;

            for (int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();
                
                if (i != 0) {
                    prev->next = node;
                }
                prev = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            prev = NULL;
        }

        return root;
    }
};