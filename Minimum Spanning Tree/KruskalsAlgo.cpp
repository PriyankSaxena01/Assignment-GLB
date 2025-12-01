#include <bits/stdc++.h>
using namespace std;

class KruskalsAlgo {
public:
    int* rank_arr;
    int* parent;

    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });

        rank_arr = new int[V];
        parent = new int[V];

        for(int i = 0; i < V; i++){
            parent[i] = i;
        }

        int sum = 0;
        for(auto p : edges){
            int u = p[0];
            int v = p[1];
            int wt = p[2];
            int pu = get(u);
            int pv = get(v);

            if(pu == pv){
                continue;
            }

            sum += wt;

            if(pu < pv){
                parent[pu] = pv;
            }
            else if(pu > pv){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank_arr[pu] = rank_arr[pu] + 1;
            }
        }
        return sum;
    }

    int get(int node){
        if(node == parent[node]){
            return node;
        }
        int p = get(parent[node]);
        parent[node] = p;
        return parent[node];
    }
};

int main(){

}
