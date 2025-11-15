#include <bits/stdc++.h>
using namespace std;

class Operations {
public:
    static void insert(priority_queue<int, vector<int>, greater<int>>& q, int k) {
        q.push(k);
    }

    static bool find(priority_queue<int, vector<int>, greater<int>> q, int k) {
        while (!q.empty()) {
            if (q.top() == k) return true;
            q.pop();
        }
        return false;
    }

    static int delete_(priority_queue<int, vector<int>, greater<int>>& q) {
        int val = q.top();
        q.pop();
        return val;
    }
};

int main() {
    
}
