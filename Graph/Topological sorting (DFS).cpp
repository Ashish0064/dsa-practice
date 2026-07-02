class Solution {
  public:
    void DFSTopologicalSort(vector<vector<int>>& adj, int u ,vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFSTopologicalSort(adj,v,visited,st);
            }
        }
        st.push(u);
        
    }
      
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V,false);
        stack<int> st;
        vector<vector<int>> adj(V);
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge [1];
            
            adj[u].push_back(v);
        }
        
        for(int i =0; i<V;i++){
            if(!visited[i]){
                DFSTopologicalSort(adj,i,visited,st);
            }
        }
        
        vector<int> result;
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};