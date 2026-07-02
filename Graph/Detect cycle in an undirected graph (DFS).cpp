class Solution {
  public:
  
    bool DFSCycle(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent) {

        visited[u] = true;

        for (int &v : adj[u]) {

            if (v == parent) continue;

            if (visited[v] == true) {
                return true;
            }

            if (DFSCycle(adj, v, visited, u)) {
                    return true;
            }
        }
            
        return false;

        
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i] && DFSCycle(adj, i, visited, -1)) {
                return true;
            }
        }

        return false;
    }
};