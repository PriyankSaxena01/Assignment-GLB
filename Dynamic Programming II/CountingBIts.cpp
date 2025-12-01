#include <bits/stdc++.h>
using namespace std;

class CountingBits {
public:
    vector<int> countBits(int n) {
        if(n == 0) {
            return vector<int>{0};
        }
        if(n == 1) {
            return vector<int>{0, 1};
        }
        if(n == 2) {
            return vector<int>{0, 1, 1};
        }

        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;

        int cur = 2;
        int next = 4;

        for(int i = 3; i <= n; i++) {
            if(i == next) {
                cur = i;
                next = i * 2;
                res[i] = 1;
            } else {
                res[i] = res[cur] + res[i - cur];
            }
        }

        return res;
    }
};

int main() {
    CountingBits cb;
    vector<int> result = cb.countBits(5);

    // Printing result similar to Arrays.toString() in Java
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]";
}
