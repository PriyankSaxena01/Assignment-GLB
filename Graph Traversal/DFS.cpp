class Solution {
  public:
  void dfs(int V,int parent,vector<bool>&visited,vector<vector<int>>& edges,vector<int>& ans){
      ans.push_back(V);
      visited[V]=true;
      for(int i=0;i<edges[V].size();i++){
          if(parent==edges[V][i]){
              continue;
          }
          if(visited[edges[V][i]]==0)
            {
                dfs(edges[V][i],visited,edges,ans);
            }
          }
      }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool>visited(V,false);
        vector<int> ans;
         for(int i=0;i<V;i++){
             if(!visited[i] &&dfs(i,-1,visited,edges,ans) ){
                 return true;
             }
         }
        return false;
    }
};
