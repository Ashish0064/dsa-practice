
class Solution {
  public:
  
    bool BFSCycle(vector<vector<int>>& adj, int V,int start, vector<bool>& visited) {
        queue<pair<int,int>> que;
        que.push({start,-1});
        visited[start] = true;
        
        while(!que.empty()){
            int curr = que.front().first ;
            int parent = que.front().second;
            
            que.pop();
            
            for(auto x: adj[curr]){
                if(visited[x] == false){
                    que.push({x,curr});
                    visited[x] = true;
                }else if(x != parent){
                    return true;
                }
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
            if (!visited[i] && BFSCycle(adj, V,i, visited)) {
                return true;
            }
        }

        return false;
    }
};