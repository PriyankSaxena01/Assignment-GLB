#include <bits/stdc++.h>
using namespace std;

class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = find(s, i, i);
            int len2 = find(s, i, i + 1);
            int len = max(len1, len2);
            if (len > right - left) {
                left = i - (len - 1) / 2;
                right = i + len / 2;
            }
        }
        return s.substr(left, right - left + 1);
    }

    int find(string& p, int s, int e) {
        while (s >= 0 && e < p.size() && p[s] == p[e]) {
            s--;
            e++;
        }
        return e - s - 1;
    }
};

int main() {
}
