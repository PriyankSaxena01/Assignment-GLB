#include <bits/stdc++.h>
using namespace std;

class PrintAllPath {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        dfs(0, graph, vector<int>(), res);
        return res;
    }

    static void dfs(int i, vector<vector<int>>& graph, vector<int> p, vector<vector<int>>& res) {
        if(i == graph.size() - 1){
            p.push_back(graph.size() - 1);
            res.push_back(p);
            p.pop_back();
            return;
        }
        for(int boundary : graph[i]){
            p.push_back(i);
            dfs(boundary, graph, p, res);
            p.pop_back();
        }
    }
};

int main() {

}
