#include <bits/stdc++.h>
using namespace std;

class FindIfPathExists {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> list;
        if(source == destination){
            return true;
        }
        for(int i = 0; i < n; i++){
            list.push_back(vector<int>());
        }
        for(auto pre : edges){
            list[pre[0]].push_back(pre[1]);
            list[pre[1]].push_back(pre[0]);
        }
        queue<int> queue;
        vector<bool> vis(n, false);
        queue.push(source);
        while(!queue.empty()){
            int u = queue.front();
            queue.pop();
            if(vis[u]){
                continue;
            }
            vis[u] = true;
            for(int neb : list[u]){
                if(neb == destination){
                    return true;
                }
                if(!vis[neb]){
                    queue.push(neb);
                }
            }
        }
        return false;
    }
};

int main(){
    
}
