#include <bits/stdc++.h>
using namespace std;

class PrimsAlgo {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<vector<int>>> list;
        for(int i = 0; i < V; i++){
            list.push_back(vector<vector<int>>());
        }

        for(auto p : edges){
            list[p[0]].push_back(vector<int>{p[2], p[1]});
            list[p[1]].push_back(vector<int>{p[2], p[0]});
        }

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        pq.push(vector<int>{0, 0});
        int sum = 0;
        vector<int> vis(V, 0);

        while(!pq.empty()){
            vector<int> arr = pq.top();
            pq.pop();

            int d = arr[0];
            int u = arr[1];

            if(vis[u] == 1){
                continue;
            }

            vis[u] = 1;
            sum += d;

            for(auto p : list[u]){
                int w = p[0];
                int v = p[1];

                if(vis[v] == 0){
                    pq.push(vector<int>{w, v});
                }
            }
        }

        return sum;
    }
};

int main() {

}
