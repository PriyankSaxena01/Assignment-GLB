class Solution {
  public:
  
    bool isSafe(int newx,int newy,vector<vector<bool>>& vis,vector<vector<int>>& arr,int n)
    {
        if( newx>=0 && newx<n && newy>=0 && newy<n && vis[newx][newy] !=1 && arr[newx][newy]==1)
        {
            return true;
        }
        else
        return false;
    }
  
    void solve(int x,int y,vector<vector<int>>& arr,int n,vector<string>& ans,vector<vector<bool>>& vis,string path )
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        // CHECK DOWN IS SAFE OR NOT
        if(isSafe(x+1,y,vis,arr,n))
        {
            vis[x][y]=1;
            solve(x+1,y,arr,n,ans,vis,path+'D');
            vis[x][y]=0;
        }
        
        // CHECK LEFT IS SAFE OR NOT
        if(isSafe(x,y-1,vis,arr,n))
        {
            vis[x][y]=1;
            solve(x,y-1,arr,n,ans,vis,path+'L');
            vis[x][y]=0;
        }
        
        // CHECK RIGHT IS SAFE OR NOT
        if(isSafe(x,y+1,vis,arr,n))
        {
            vis[x][y]=1;
            solve(x,y+1,arr,n,ans,vis,path+'R');
            vis[x][y]=0;
        }
        
        // CHECK UP IS SAFE OR NOT
        if(isSafe(x-1,y,vis,arr,n))
        {
            vis[x][y]=1;
            solve(x-1,y,arr,n,ans,vis,path+'U');
            vis[x][y]=0;
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& arr) {
        // code here
        vector<string> ans;
        int n=arr.size();
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        string path="";
        solve(0,0,arr,arr.size(),ans,vis,path);
        return ans;
    }
};
