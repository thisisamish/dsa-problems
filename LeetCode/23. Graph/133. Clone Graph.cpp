// Written By - Amish Verma (@thisisamish)
// Approach 1 : DFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});

            for (Node* nei : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(nei));
            }
        }

        return copies[node];
    }
};

// Approach 2 : BFS

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        Node* copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* nei : curr->neighbors) {
                if (copies.find(nei) == copies.end()) {
                    copies[nei] = new Node(nei->val, {});
                    q.push(nei);
                }

                copies[curr]->neighbors.push_back(copies[nei]);
            }
        }

        return copy;
    }
};