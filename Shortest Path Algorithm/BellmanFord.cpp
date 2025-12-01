#include <bits/stdc++.h>
using namespace std;

class BellmanFord {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V);
        int mod = 100000000;
        fill(dist.begin(), dist.end(), mod);
        dist[src] = 0;

        for(int i = 0; i < V; i++){
            for(int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u] != mod && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(int j = 0; j < edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != mod && dist[u] + wt < dist[v]){
                return vector<int>{-1};
            }
        }

        return dist;
    }
};

int main(){

}
