#include <bits/stdc++.h>
using namespace std;

class PalindromicSubstrings {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int len1 = find(s, i, i);
            int len2 = find(s, i, i + 1);
            sum += len1 + len2;
        }
        return sum;
    }

    int find(string& p, int s, int e) {
        int c = 0;
        while (s >= 0 && e < p.size() && p[s] == p[e]) {
            c++;
            s--;
            e++;
        }
        return c;
    }
};

int main() {
}
