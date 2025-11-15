class Solution {
  public:
  bool dfs(int V,int parent,vector<bool>&visited,vector<vector<int>>& edges){
      visited[V]=true;
      for(int i=0;i<edges[V].size();i++){
          if(parent==edges[V][i]){
              continue;
          }
          if(visited[edges[V][i]]==1){
              return true;
          }
          if(dfs(edges[V][i],V,visited,edges)){
              return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool>visited(V,false);
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
         for(int i=0;i<V;i++){
             if(!visited[i] &&dfs(i,-1,visited,adj) ){
                 return true;
             }
         }
        return false;
    }
};
