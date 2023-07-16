// Written By - Amish Verma (@thisisamish)
// Approach 1 : BFS
// TC is O(V + 2E) and SC is O(V)

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int& nei : graph[node]) {
                if (color[nei] == -1) {
                    color[nei] = !color[node];
                    q.push(nei);
                } else if (color[nei] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if(!bfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Approach 2 : DFS
// TC is O(V + 2E) and SC is O(V)

class Solution {
public:
    bool dfs(int node, int clr, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = clr;

        for (int& nei : graph[node]) {
            if (color[nei] == -1) {
                if(!dfs(nei, !clr, graph, color)) {
                    return false;
                }
            }
            else if (color[nei] == clr) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if(!dfs(i, 0, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};