class Solution {
  public:
    bool DFSCycle(vector<vector<int>>& adj, int u,vector<bool>& visited, vector<bool>& inRecursion){
        visited[u]= true;
        inRecursion[u] = true;
        
        for(auto &v: adj[u]){
            //case 1: if not visited we check again by calling DFSCycle function..
            if(visited[v] == false && DFSCycle(adj,v,visited,inRecursion)){
                return true;
            }
            //case 2: if visited is true then we check is inRecursion its also visited if yes then its cycle
            else if(inRecursion[v]== true)
                return true;
        }
        inRecursion[u] = false;
        return false;
    }
  
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
        
        for(int i = 0;i<V;i++){
            if(!visited[i] && DFSCycle(adj,i,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};