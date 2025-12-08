#include <bits/stdc++.h>
using namespace std;

class DijkstraAlgo {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {

        vector<vector<vector<int>>> list;
        for(int i = 0; i < V; i++){
            list.push_back(vector<vector<int>>());
        }

        for(auto p : edges){
            int u = p[0];
            list[u].push_back(vector<int>{p[2], p[1]});
        }

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        vector<int> source(2);
        source[1] = src;
        pq.push(source);

        while(!pq.empty()){
            vector<int> arr = pq.top();
            pq.pop();

            int x = arr[0];
            int u = arr[1];

            if(x > dist[u]){
                continue;
            }

            for(auto neb : list[u]){
                int y = neb[0];
                int v = neb[1];

                if(y + x < dist[v]){
                    dist[v] = y + x;

                    vector<int> num(2);
                    num[0] = x + y;
                    num[1] = v;
                    pq.push(num);
                }
            }
        }

        return dist;
    }
};

int main(){

}
