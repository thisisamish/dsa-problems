// Written By - Amish Verma
// Approach 1 : DFS
// TC is O(V + E), SC is O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int node, vector<int> adj[], stack<int>& s, int visited[]) {
        if (!visited[node]) {
            visited[node] = 1;
            for (int& nei : adj[node]) {
                dfs(nei, adj, s, visited);
            }
            s.push(node);
        }   
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int visited[V] = {0};
	    stack<int> s;
	    vector<int> ans;
	    
	    for (int i = 0; i < V; i++) {
	        if (!visited[i]) {
	            dfs(i, adj, s, visited);
	        }
	    }
	    
	    while (!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends

// Approach 2 : Kahn's Algorithm (modified BFS)
// TC is O(V + E), SC is O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
	    for (int i = 0; i < V; i++) {
	        for (int& node : adj[i]) {
	            indegree[node]++;
	        }
	    }
	    
	    queue<int> q;
	    for (int i = 0; i < V; i++) {
	        if (indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    while (!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for (int& nei : adj[node]) {
	            indegree[nei]--;
	            if (indegree[nei] == 0) {
	                q.push(nei);
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends