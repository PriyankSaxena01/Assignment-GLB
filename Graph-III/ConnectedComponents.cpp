#include <bits/stdc++.h>
using namespace std;

class ConnectedComponents {
public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &d : edges) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<vector<int>> res;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> p;
                dfs(i, visited, adj, p);
                res.push_back(p);
            }
        }
        return res;
    }

    void dfs(int i, vector<bool>& visited, vector<vector<int>>& list, vector<int>& res) {
        visited[i] = true;
        res.push_back(i);
        for (int boundary : list[i]) {
            if (!visited[boundary]) {
                dfs(boundary, visited, list, res);
            }
        }
    }
};
