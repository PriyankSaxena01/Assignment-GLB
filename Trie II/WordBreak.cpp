#include <bits/stdc++.h>
using namespace std;

class WordBreak {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        return find(s, wordDict, memo);
    }

private:
    bool find(string s, vector<string>& wordDict, unordered_map<string, bool>& memo) {
        if(s.empty()) return true;

        if(memo.find(s) != memo.end()) 
            return memo[s];

        for(string word : wordDict) {

            if(s.rfind(word, 0) == 0) { // same as s.startsWith(word)
                string suffix = s.substr(word.length());

                if(find(suffix, wordDict, memo)) {
                    memo[s] = true;
                    return true;
                }
            }
        }

        memo[s] = false;
        return false;
    }
};

int main() {

}
